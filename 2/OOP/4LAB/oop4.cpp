#include <iostream>
#include <string>
using namespace std;
#include "Jel_Vagon.h"
#include "Kup_Vagon.h"
#include "Plac_Vagon.h"
#include "Sid_Vagon.h"

int main()
{
	setlocale(LC_ALL, "RU");
	//общая информация
	Jel_Vagon jel_vagon("Железнодорожный", 50, 2000, 2500);
	jel_vagon.show_info();
	//сидячий вагон
	Sid_Vagon sid_vagon(1000, 30, "Сидячий", 50);
	sid_vagon.sit_info();
	sid_vagon.makeMoney(3);
	//плацкарт
	Plac_Vagon plac_vagon(1500, 2000, 15, 15, "Плацкарт", 40);
	plac_vagon.econom_info();
	plac_vagon.makeMoney(4);
	//купе
	Kup_Vagon kup_vagon(3000, 4000, 15, 15, "Купе", 50);
	kup_vagon.kup_info();
	kup_vagon.makeMoney(3);
}

