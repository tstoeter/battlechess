#include <stdio.h>
#include <glib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "board.h"
#include "game.h"
#include "graphics.h"
#include "movement.h"

#define FPS 60

ALLEGRO_DISPLAY 	*display;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER 		*timer;

ALLEGRO_EVENT 		event;
ALLEGRO_TIMEOUT		timeout;
ALLEGRO_MOUSE_STATE mouse_state;

bool redraw;
bool running;
short state;

void clear_board(Square (*board)[8][8])
{
	short y;
	short x;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			if (board[y][x]->piece != NULL) {
				al_free(board[y][x]->piece);
			}
			board[y][x]->piece = NULL;
		}
	}
}

void game_loop()
{
	// Fetch the event (if one exists)
	bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
	if (get_event) {
		switch (event.type) {
			case ALLEGRO_EVENT_TIMER:
				// process logic
				redraw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				running = false;
				break;
			default:
				game_event(&event);
				break;
		}
	}

	if (!running) {
		return;
	}

	game_run();

	if (redraw && al_is_event_queue_empty(event_queue)) {
		game_redraw();
		redraw = false;
	}
}

int main(int argc, char *argv[])
{
	running = true;
	redraw = true;
	state = PLAYING;

	screen_width = 640;
	screen_height = 480;

	//{{{ initialization
	
	// Initialize allegro
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

	// Initialize allegro_image addon
	if (!al_init_image_addon()) {
		fprintf(stderr, "Failed to initialize image addon.\n");
		return 1;
	}

	// Initialize the timer
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer.\n");
		return 1;
	}

	// Install the mouse
	if (!al_install_mouse()) {
		fprintf(stderr, "Failed to install mouse.\n");
		return 1;
	}

	// Install the font addon
	al_init_font_addon();

	// Create the display
	display = al_create_display(screen_width, screen_height);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return 1;
	} else {
		al_set_window_title(display, "Battle Chess!");
	}

	// Create the event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event queue.\n");
		return 1;
	}

	// Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//}}}
	
	// Start the timer
	al_start_timer(timer);

	al_init_timeout(&timeout, 0.06);

	al_clear_to_color(al_map_rgb(100, 100, 100));
	al_flip_display();

	// ???: why the hell does this not work the other way around?
	load_game();
	init_graphics();

	// Main loop
	while (running) {
		al_get_mouse_state(&mouse_state);
		mouse_x = mouse_state.x;
		mouse_y = mouse_state.y;

		switch (state) {
			case PLAYING:
				game_loop();
				break;
			default:
				fprintf(stderr, "unknown state: %d\n", state);
				break;
		}
	}
}
