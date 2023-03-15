#include "UI.h"

int main()
{
	UI ui(1920, 1080, "UI");
	ui.init();

	ui.addButton(0, 0, 250, 250, "menu", "image/solution_edit3.png");
	ui.addButton(250, 250, 250, 250, "menu2", "image/solution_edit3.png");
	
	ui.progress();

	return 0;
}