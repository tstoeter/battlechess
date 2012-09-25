#include <stdio.h>
#include <allegro5/allegro.h>
#include <glib.h>

int main(int argc, char *argv[])
{
	uint32_t al_version = al_get_allegro_version();
	int al_major_version = al_version >> 24;
	int al_minor_version = (al_version >> 16) & 255;
	int al_revision = (al_version >> 8) & 255;
	printf("allegro version: %d.%d.%d\n", al_major_version, al_minor_version, al_revision);

	printf("glib version: %d.%d.%d\n", glib_major_version, glib_minor_version, glib_micro_version);
	return 0;
}
