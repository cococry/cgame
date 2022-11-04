#include "pch.h"
#include "application.h"

int main(void) {
	window_properties props = {1920, 1080, 0, 30, "Game in C", true, true, false};
	application app = create_application(props);
	update_application(&app);
	shutdown_application(&app);
}