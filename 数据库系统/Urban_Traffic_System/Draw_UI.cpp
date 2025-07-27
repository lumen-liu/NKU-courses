#include "Draw_UI.h"

int screenWidth = GetSystemMetrics(SM_CXSCREEN); // 获取屏幕宽度
int screenHeight = GetSystemMetrics(SM_CYSCREEN); // 获取屏幕高度
int windowX = (screenWidth - WIDTH) / 2; // 计算窗口左上角的 X 坐标
int windowY = (screenHeight - HEIGHT) / 2; // 计算窗口左上角的 Y 坐标


IMAGE im_login;
void DRAW_LOGIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_login, "pic/login.png");
    putimage(0, 0, &im_login);


    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 52 && x < 292 && y> 310 && y < 370)//跳转到CITY界面
            {
                closegraph(); 
                DRAW_CITY_MAIN();
            }
            if (x > 452 && x < 691 && y> 310 && y < 370)//跳转到STATION界面
            {
                closegraph(); 
                DRAW_STATION_MAIN();
            }
            if (x > 852 && x < 1092 && y> 310 && y < 370)//跳转到PASSENGER界面
            {
                closegraph();
                DRAW_PASSENGER_MAIN();
            }
            if (x > 52 && x < 292 && y> 425 && y < 488)//跳转到LINE界面
            {
                closegraph();
                DRAW_LINE_MAIN();
            }
            if (x > 452 && x < 691 && y> 425 && y < 488)//跳转到LINE界面
            {
                closegraph(); 
                DRAW_VEHICLE_MAIN();
            }
            if (x > 852 && x < 1092 && y> 425 && y < 488)//跳转到OTHERS界面
            {
                closegraph(); 
                DRAW_OTHERS_MAIN();
            }
        }
    }
}

IMAGE im_city_main;
void DRAW_CITY_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_city_main, "pic/city_main.png");
    putimage(0, 0, &im_city_main);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 47 && x < 265 && y> 267 && y < 345)//跳转到CITY_SELECT界面
            {
                closegraph(); 
                DRAW_CITY_SELECT();
            }
            if (x > 319 && x < 538 && y> 267 && y < 345)//跳转到CITY_INSERT界面
            {
                DRAW_CITY_INSERT();
            }
            if (x > 589 && x < 815 && y> 267 && y < 345)//跳转到CITY_UPDATE界面
            {
                DRAW_CITY_UPDATE();
            }
            if (x > 869 && x < 1087 && y> 267 && y < 345)//跳转到CITY_DELETE界面
            {
                DRAW_CITY_DELETE();
            }
            if (x > 439 && x < 694 && y> 468 && y < 555)//跳转到LOGIN界面
            {
                closegraph(); 
                DRAW_LOGIN();
            }
        }
    }
}
IMAGE im_city_select;
void DRAW_CITY_SELECT()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_city_select, "pic/city_select.png");
    putimage(0, 0, &im_city_select);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 47 && x < 266 && y> 253 && y < 419)//跳转到DRAW_CITY_Get_Citys_All界面
            {
                closegraph(); 
                DRAW_CITY_SELECT_CITIES_ALL();
            }
            if (x > 428 && x < 699 && y> 253 && y < 419)//跳转到DRAW_CITY_Get_Includes_All界面
            {
                closegraph();
                DRAW_CITY_SELECT_STATIONS();
            }
            if (x > 862 && x < 1087 && y> 253 && y < 419)//跳转到DRAW_CITY_Get_Lines_All界面
            {
                closegraph(); 
                DRAW_CITY_SELECT_LINES();
            }
            if (x > 437 && x < 691 && y> 455 && y < 542)//跳转到CITY_MAIN界面
            {
                closegraph(); 
                DRAW_CITY_MAIN();
            }
        }
    }
}
IMAGE im_city_select_cities;
void DRAW_CITY_SELECT_CITIES_ALL()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_city_select_cities, "pic/city_select_cities.png");
    putimage(0, 0, &im_city_select_cities);

    vector<City>cities = Manager::GetInstance()->Get_Citys_All();
    int y = 110;
    for (const auto& city : cities) 
    {
        string text = "City_id: " + to_string(city.city_id)  + "  Population: " + to_string(city.population) + "  Name: " + city.name;
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 694 && y> 493 && y < 580)//跳转到DRAW_CITY_SELECT界面
            {
                closegraph();
                DRAW_CITY_SELECT();
            }
        }
    }
}
IMAGE im_city_select_stations;
void DRAW_CITY_SELECT_STATIONS()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_city_select_stations, "pic/city_select_stations.png");
    putimage(0, 0, &im_city_select_stations);

    vector<Include>ret = Manager::GetInstance()->Get_Includes_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "City_id: " + to_string(t.city_id) + "  Station_id: " + to_string(t.station_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_CITY_SELECT界面
            {
                closegraph();
                DRAW_CITY_SELECT();
            }
        }
    }
}
IMAGE im_city_select_lines;
void DRAW_CITY_SELECT_LINES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_city_select_lines, "pic/city_select_lines.png");
    putimage(0, 0, &im_city_select_lines);

    vector<Setting>ret = Manager::GetInstance()->Get_Settings_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "City_id: " + to_string(t.city_id) + "  Line_id: " + to_string(t.line_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_CITY_SELECT界面
            {
                closegraph();
                DRAW_CITY_SELECT();
            }
        }
    }
}
IMAGE im_city_insert;
void DRAW_CITY_INSERT()
{

    int xPos = WIDTH/2; // X 坐标
    int yPos = HEIGHT/2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待插入的城市信息:", "输入信息", MB_OK);

    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);
    CHAR citypopulation[100];
    InputBox(citypopulation, 100, "city_population", "输入信息", "", xPos, yPos);
    int city_population = atoi(citypopulation);
    CHAR cityname[100];
    InputBox(cityname, 100, "city_name", "输入信息", "", xPos, yPos);
    string city_name(cityname);

    City city(city_id, city_population, city_name);
    if (Manager::GetInstance()->Insert_City(city))
    {
        MessageBox(hwnd, "插入成功", "提示", MB_OK);
    }

}
void DRAW_CITY_UPDATE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的城市信息:", "输入信息", MB_OK);

    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);
    CHAR citypopulation[100];
    InputBox(citypopulation, 100, "city_population", "输入信息", "", xPos, yPos);
    int city_population = atoi(citypopulation);
    CHAR cityname[100];
    InputBox(cityname, 100, "city_name", "输入信息", "", xPos, yPos);
    string city_name(cityname);

    City city(city_id, city_population, city_name);
    if (Manager::GetInstance()->Update_City(city))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
void DRAW_CITY_DELETE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待删除的城市信息:", "输入信息", MB_OK);
    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);

    if (Manager::GetInstance()->Delete_City(city_id))
    {
        MessageBox(hwnd, "删除成功", "提示", MB_OK);
    }
}

IMAGE im_station_main;
void DRAW_STATION_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_station_main, "pic/station_main.png");
    putimage(0, 0, &im_station_main);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 47 && x < 265 && y> 267 && y < 345)//跳转到STATION_SELECT界面
            {
                closegraph();
                DRAW_STATION_SELECT();
            }
            if (x > 319 && x < 538 && y> 267 && y < 345)//跳转到STATION_INSERT界面
            {
                DRAW_STATION_INSERT();
            }
            if (x > 589 && x < 815 && y> 267 && y < 345)//跳转到STATION_UPDATE界面
            {
                DRAW_STATION_UPDATE();
            }
            if (x > 869 && x < 1087 && y> 267 && y < 345)//跳转到STATION_DELETE界面
            {
                DRAW_STATION_DELETE();
            }
            if (x > 439 && x < 694 && y> 468 && y < 555)//跳转到LOGIN界面
            {
                closegraph();
                DRAW_LOGIN();
            }
        }
    }
}
IMAGE im_station_select;
void DRAW_STATION_SELECT()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_station_select, "pic/station_select.png");
    putimage(0, 0, &im_station_select);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 46 && x < 265 && y> 257 && y < 423)//跳转到DRAW_STATION_Get_Stations_All界面
            {
                closegraph();
                DRAW_STATION_SELECT_STATIONS_ALL();
            }
            if (x > 429 && x < 699 && y> 257 && y < 423)//跳转到DRAW_STATION_Get_Serves_All界面
            {
                closegraph();
                DRAW_STATION_SELECT_CITIES();
            }
            if (x > 861 && x < 1086 && y> 257 && y < 423)//跳转到DRAW_STATION_Get_Passengers_All界面
            {
                closegraph();
                DRAW_STATION_SELECT_PASSENGERS();
            }
            if (x > 436 && x < 691 && y> 459 && y < 545)//跳转到STATION_MAIN界面
            {
                closegraph();
                DRAW_STATION_MAIN();
            }
        }
    }
}
IMAGE im_station_select_stations;
void DRAW_STATION_SELECT_STATIONS_ALL()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_station_select_stations, "pic/station_select_stations.png");
    putimage(0, 0, &im_station_select_stations);

    vector<Station>ret = Manager::GetInstance()->Get_Stations_All();
    int y = 110;
    for (const auto& t : ret)
    {
        string text = "Station_id: " + to_string(t.station_id) + "  Name: " + t.name + "  Latitude:" + to_string(t.latitude) + "  Longitude:" + to_string(t.longitude) + "  City_id:" + to_string(t.city_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 448 && x < 703 && y> 485 && y < 569)//跳转到DRAW_STATION_SELECT界面
            {
                closegraph();
                DRAW_STATION_SELECT();
            }
        }
    }
}
IMAGE im_station_select_cities;
void DRAW_STATION_SELECT_CITIES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_station_select_cities, "pic/station_select_cities.png");
    putimage(0, 0, &im_station_select_cities);

    vector<Include>ret = Manager::GetInstance()->Get_Includes_All();
    int y = 110;
    for (auto& t : ret)
    {
        std::string text = "City_id: " + to_string(t.city_id) + "  Station_id: " + to_string(t.station_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 436 && x < 691 && y> 488 && y < 572)//跳转到DRAW_STATION_SELECT界面
            {
                closegraph();
                DRAW_STATION_SELECT();
            }
        }
    }
}
IMAGE im_station_select_passengers;
void DRAW_STATION_SELECT_PASSENGERS()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_station_select_passengers, "pic/station_select_passengers.png");
    putimage(0, 0, &im_station_select_passengers);

    vector<Serve>ret = Manager::GetInstance()->Get_Serves_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Station_id: " + to_string(t.station_id) + "  Passenger_id: " + to_string(t.passenger_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_STATION_SELECT界面
            {
                closegraph();
                DRAW_STATION_SELECT();
            }
        }
    }
}
void DRAW_STATION_INSERT()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待插入的站点信息:", "输入信息", MB_OK);

    TCHAR stationid[100];
    InputBox(stationid, 100, "station_id", "输入信息", "", xPos, yPos);
    int station_id = atoi(stationid);
    CHAR stationname[100];
    InputBox(stationname, 100, "name", "输入信息", "", xPos, yPos);
    string station_name(stationname);
    CHAR stationlatitude[100];
    InputBox(stationlatitude, 100, "latitude", "输入信息", "", xPos, yPos);
    double station_latitude = atof(stationlatitude);
    CHAR stationlongitude[100];
    InputBox(stationlongitude, 100, "longitude", "输入信息", "", xPos, yPos);
    double station_longitude = atof(stationlongitude);
    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);

    Station station(station_id, station_name, station_latitude, station_longitude, city_id);
    if (Manager::GetInstance()->Insert_Station(station))
    {
        MessageBox(hwnd, "插入成功", "提示", MB_OK);
    }
}
void DRAW_STATION_UPDATE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的站点信息:", "输入信息", MB_OK);

    TCHAR stationid[100];
    InputBox(stationid, 100, "station_id", "输入信息", "", xPos, yPos);
    int station_id = atoi(stationid);
    CHAR stationname[100];
    InputBox(stationname, 100, "name", "输入信息", "", xPos, yPos);
    string station_name(stationname);
    CHAR stationlatitude[100];
    InputBox(stationlatitude, 100, "latitude", "输入信息", "", xPos, yPos);
    double station_latitude = atof(stationlatitude);
    CHAR stationlongitude[100];
    InputBox(stationlongitude, 100, "longitude", "输入信息", "", xPos, yPos);
    double station_longitude = atof(stationlongitude);
    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);

    Station station(station_id, station_name, station_latitude, station_longitude, city_id);
    if (Manager::GetInstance()->Update_Station(station))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
void DRAW_STATION_DELETE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待删除的站点信息:", "输入信息", MB_OK);
    TCHAR stationid[100];
    InputBox(stationid, 100, "station_id", "输入信息", "", xPos, yPos);
    int station_id = atoi(stationid);

    if (Manager::GetInstance()->Delete_Station(station_id))
    {
        MessageBox(hwnd, "删除成功", "提示", MB_OK);
    }
}

IMAGE im_passenger_main;
void DRAW_PASSENGER_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_passenger_main, "pic/passenger_main.png");
    putimage(0, 0, &im_passenger_main);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 51 && x < 270 && y> 262 && y < 429)//跳转到PASSENGER_SELECT界面  
            {
                closegraph();
                DRAW_PASSENGER_SELECT();
            }
            if (x > 321 && x < 540 && y> 262 && y < 429)//跳转到PASSENGER_INSERT界面
            {
                DRAW_PASSENGER_INSERT();
            }
            if (x > 594 && x < 819 && y> 262 && y < 429)//跳转到PASSENGER_UPDATE界面
            {
                DRAW_PASSENGER_UPDATE();
            }
            if (x > 873 && x < 1092 && y> 262 && y < 429)//跳转到PASSENGER_DELETE界面
            {
                DRAW_PASSENGER_DELETE();
            }
            if (x > 444 && x < 699 && y> 462 && y < 549)//跳转到LOGIN界面
            {
                closegraph();
                DRAW_LOGIN();
            }
        }
    }
}
IMAGE im_passenger_select;
void DRAW_PASSENGER_SELECT()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_passenger_select, "pic/passenger_select.png");
    putimage(0, 0, &im_passenger_select);

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 210 && x < 429 && y> 255 && y < 420)//跳转到DRAW_PASSENGER_Get_Passengers_All界面
            {
                closegraph();
                DRAW_PASSENGER_SELECT_PASSENGERS_ALL();
            }
            if (x > 711 && x < 981 && y> 255 && y < 420)//跳转到DRAW_PASSENGER_Get_Serves_All界面
            {
                closegraph();
                DRAW_PASSENGER_SELECT_STATIONS();
            }
            if (x > 441 && x < 696 && y> 456 && y < 540)//跳转到PASSENGER_MAIN界面
            {
                closegraph();
                DRAW_PASSENGER_MAIN();
            }
        }
    }
}
IMAGE im_passenger_select_passengers;
void DRAW_PASSENGER_SELECT_PASSENGERS_ALL()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_passenger_select_passengers, "pic/passenger_select_passengers.png");
    putimage(0, 0, &im_passenger_select_passengers);

    vector<Passenger>ret = Manager::GetInstance()->Get_Passengers_All();
    int y = 110;
    for (const auto& t : ret)
    {
        string text = "Passenger_id: " + to_string(t.passenger_id) + "  Name: " + t.name + "  Age:" + to_string(t.age) + "  Gender:" + t.gender;
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 448 && x < 703 && y> 485 && y < 569)//跳转到DRAW_PASSENGER_SELECT界面
            {
                closegraph();
                DRAW_PASSENGER_SELECT();
            }
        }
    }
}
IMAGE im_passenger_select_stations;
void DRAW_PASSENGER_SELECT_STATIONS()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_passenger_select_stations, "pic/passenger_select_stations.png");
    putimage(0, 0, &im_passenger_select_stations);

    vector<Serve>ret = Manager::GetInstance()->Get_Serves_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Station_id: " + to_string(t.station_id) + "  Passenger_id: " + to_string(t.passenger_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_PASSENGER_SELECT界面
            {
                closegraph();
                DRAW_PASSENGER_SELECT();
            }
        }
    }
}
void DRAW_PASSENGER_INSERT()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待插入的乘客信息:", "输入信息", MB_OK);

    TCHAR passengerid[100];
    InputBox(passengerid, 100, "passenger_id", "输入信息", "", xPos, yPos);
    int passenger_id = atoi(passengerid);
    CHAR passengername[100];
    InputBox(passengername, 100, "name", "输入信息", "", xPos, yPos);
    string passenger_name(passengername);
    CHAR passengerage[100];
    InputBox(passengerage, 100, "age", "输入信息", "", xPos, yPos);
    int passenger_age = atoi(passengerage);
    CHAR passengergender[100];
    InputBox(passengergender, 100, "gender", "输入信息", "", xPos, yPos);
    string passenger_gender(passengergender);

    Passenger passenger(passenger_id, passenger_name, passenger_age, passenger_gender);
    if (Manager::GetInstance()->Insert_Passenger(passenger))
    {
        MessageBox(hwnd, "插入成功", "提示", MB_OK);
    }
}
void DRAW_PASSENGER_UPDATE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的乘客信息:", "输入信息", MB_OK);

    TCHAR oldpassengerid[100];
    InputBox(oldpassengerid, 100, "oldpassenger_id", "输入信息", "", xPos, yPos);
    int old_passenger_id = atoi(oldpassengerid);
    TCHAR passengerid[100];
    InputBox(passengerid, 100, "passenger_id", "输入信息", "", xPos, yPos);
    int passenger_id = atoi(passengerid);
    CHAR passengername[100];
    InputBox(passengername, 100, "name", "输入信息", "", xPos, yPos);
    string passenger_name(passengername);
    CHAR passengerage[100];
    InputBox(passengerage, 100, "age", "输入信息", "", xPos, yPos);
    int passenger_age = atoi(passengerage);
    CHAR passengergender[100];
    InputBox(passengergender, 100, "gender", "输入信息", "", xPos, yPos);
    string passenger_gender(passengergender);

    Station tmp(101, "beijingnan", 1, 1, 1);
    Manager::GetInstance()->Insert_Station(tmp);

    Passenger passenger(passenger_id, passenger_name, passenger_age, passenger_gender);
    if (Manager::GetInstance()->Update_Passenger(passenger,old_passenger_id))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
void DRAW_PASSENGER_DELETE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待删除的乘客信息:", "输入信息", MB_OK);
    TCHAR passengerid[100];
    InputBox(passengerid, 100, "passenger_id", "输入信息", "", xPos, yPos);
    int passenger_id = atoi(passengerid);

    if (Manager::GetInstance()->Delete_Passenger(passenger_id))
    {
        MessageBox(hwnd, "删除成功", "提示", MB_OK);
    }
}

IMAGE im_line_main;
void DRAW_LINE_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_line_main, "pic/line_main.png");
    putimage(0, 0, &im_line_main);

    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 46 && x < 262 && y> 238 && y < 406)//跳转到LINE_SELECT界面
            {
                closegraph();
                DRAW_LINE_SELECT();
            }
            if (x > 317 && x < 535 && y> 238 && y < 406)//跳转到LINE_INSERT界面
            {
                DRAW_LINE_INSERT();
            }
            if (x > 588 && x < 814 && y> 238 && y < 406)//跳转到LINE_UPDATE界面
            {
                DRAW_LINE_UPDATE();
            }
            if (x > 868 && x < 1086 && y> 238 && y < 406)//跳转到LINE_DELETE界面
            {
                DRAW_LINE_DELETE();
            }
            if (x > 438 && x < 693 && y> 441 && y < 525)//跳转到LOGIN界面
            {
                closegraph();
                DRAW_LOGIN();
            }
        }
    }
}
IMAGE im_line_select;
void DRAW_LINE_SELECT()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_line_select, "pic/line_select.png");
    putimage(0, 0, &im_line_select);

    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 52 && x < 270 && y> 253 && y < 419)//跳转到DRAW_LINE_Get_Lines_All界面
            {
                closegraph();
                DRAW_LINE_SELECT_LINES_ALL();
            }
            if (x > 432 && x < 704 && y> 253 && y < 419)//跳转到DRAW_LINE_Get_Settings_All界面
            {
                closegraph();
                DRAW_LINE_SELECT_CITIES();
            }
            if (x > 865 && x < 1090 && y> 253 && y < 419)//跳转到DRAW_LINE_Get_Vehicles_All界面
            {
                closegraph();
                DRAW_LINE_SELECT_VEHICLES();
            }
            if (x > 442 && x < 695 && y> 453 && y < 541)//跳转到LINE_MAIN界面
            {
                closegraph();
                DRAW_LINE_MAIN();
            }
        }
    }
}
IMAGE im_line_select_lines;
void DRAW_LINE_SELECT_LINES_ALL()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_line_select_lines, "pic/line_select_lines.png");
    putimage(0, 0, &im_line_select_lines);

    vector<Line>ret = Manager::GetInstance()->Get_Lines_All();
    int y = 110;
    for (const auto& t : ret)
    {
        string text = "Line_id: " + to_string(t.line_id) + "  Name: " + t.name + "  City_id:" + to_string(t.city_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true) 
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 442 && x < 696 && y> 498 && y < 585)//跳转到DRAW_LINE_SELECT界面
            {
                closegraph();
                DRAW_LINE_SELECT();
            }
        }
    }
}
IMAGE im_line_select_cities;
void DRAW_LINE_SELECT_CITIES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_line_select_cities, "pic/line_select_cities.png");
    putimage(0, 0, &im_line_select_cities);

    vector<Setting>ret = Manager::GetInstance()->Get_Settings_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "City_id: " + to_string(t.city_id) + "  Line_id: " + to_string(t.line_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 437 && x < 692 && y> 486 && y < 572)//跳转到DRAW_LINE_SELECT界面
            {
                closegraph();
                DRAW_LINE_SELECT();
            }
        }
    }
}
IMAGE im_line_select_vehicles;
void DRAW_LINE_SELECT_VEHICLES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_line_select_vehicles, "pic/line_select_vehicles.png");
    putimage(0, 0, &im_line_select_vehicles);

    vector<Offer>ret = Manager::GetInstance()->Get_Offers_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Line_id: " + to_string(t.line_id) + "  Vehicle_id: " + to_string(t.vehicle_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_LINE_SELECT界面
            {
                closegraph();
                DRAW_LINE_SELECT();
            }
        }
    }
}
void DRAW_LINE_INSERT()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待插入的线路信息:", "输入信息", MB_OK);

    TCHAR lineid[100];
    InputBox(lineid, 100, "line_id", "输入信息", "", xPos, yPos);
    int line_id = atoi(lineid);
    CHAR linename[100];
    InputBox(linename, 100, "name", "输入信息", "", xPos, yPos);
    string line_name(linename);
    CHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);

    Line line(line_id, line_name, city_id);
    if (Manager::GetInstance()->Insert_Line(line))
    {
        MessageBox(hwnd, "插入成功", "提示", MB_OK);
    }
}
void DRAW_LINE_UPDATE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的线路信息:", "输入信息", MB_OK);

    TCHAR lineid[100];
    InputBox(lineid, 100, "line_id", "输入信息", "", xPos, yPos);
    int line_id = atoi(lineid);
    CHAR linename[100];
    InputBox(linename, 100, "name", "输入信息", "", xPos, yPos);
    string line_name(linename);
    CHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);

    Line line(line_id, line_name, city_id);
    if (Manager::GetInstance()->Update_Line(line))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
void DRAW_LINE_DELETE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待删除的线路信息:", "输入信息", MB_OK);

    TCHAR lineid[100];
    InputBox(lineid, 100, "line_id", "输入信息", "", xPos, yPos);
    int line_id = atoi(lineid);

    if (Manager::GetInstance()->Delete_Line(line_id))
    {
        MessageBox(hwnd, "删除成功", "提示", MB_OK);
    }
}

IMAGE im_vehicle_main;
void DRAW_VEHICLE_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_main, "pic/vehicle_main.png");
    putimage(0, 0, &im_vehicle_main);

    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 49 && x < 268 && y> 234 && y < 402)//跳转到VEHICLE_SELECT界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT();
            }
            if (x > 319 && x < 540 && y> 234 && y < 402)//跳转到VEHICLE_INSERT界面
            {
                DRAW_VEHICLE_INSERT();
            }
            if (x > 594 && x < 817 && y> 234 && y < 402)//跳转到VEHICLE_UPDATE界面
            {
                DRAW_VEHICLE_UPDATE();
            }
            if (x > 871 && x < 1090 && y> 234 && y < 402)//跳转到VEHICLE_DELETE界面
            {
                DRAW_VEHICLE_DELETE();
            }
            if (x > 442 && x < 697 && y> 436 && y < 523)//跳转到LOGIN界面
            {
                closegraph();
                DRAW_LOGIN();
            }
        }
    }
}
IMAGE im_vehicle_select;
void DRAW_VEHICLE_SELECT()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_select, "pic/vehicle_select.png");
    putimage(0, 0, &im_vehicle_select);

    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 40 && x < 257 && y> 269 && y < 436)//跳转到DRAW_VEHICLE_Get_Vehicles_All界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT_VEHICLES_ALL();
            }
            if (x > 316 && x < 541 && y> 269 && y < 436)//跳转到DRAW_VEHICLE_Get_Offers_All界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT_LINES();
            }
            if (x > 599 && x < 823 && y> 269 && y < 436)//跳转到DRAW_VEHICLE_Get_Vehicle_Buses_All界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT_BUSES();
            }
            if (x > 881 && x < 1140 && y> 269 && y < 436)//跳转到DRAW_VEHICLE_Get_Vehicle_Subways_All界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT_SUBWAYS();
            }
            if (x > 446 && x < 699 && y> 470 && y < 557)//跳转到VEHICLE_MAIN界面
            {
                closegraph();
                DRAW_VEHICLE_MAIN();
            }
        }
    }
}
IMAGE im_vehicle_select_vehicles;
void DRAW_VEHICLE_SELECT_VEHICLES_ALL()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_select_vehicles, "pic/vehicle_select_vehicles.png");
    putimage(0, 0, &im_vehicle_select_vehicles);

    vector<Vehicle>ret = Manager::GetInstance()->Get_Vehicles_All();
    int y = 110;
    for (const auto& t : ret)
    {
        string text = "Vehicle_id: " + to_string(t.vehicle_id) + "  Model: " + t.model + "  Line_id:" + to_string(t.line_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 437 && x < 691 && y> 500 && y < 585)//跳转到DRAW_VEHICLE_SELECT界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT();
            }
        }
    }
}
IMAGE im_vehicle_select_lines;
void DRAW_VEHICLE_SELECT_LINES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_select_lines, "pic/vehicle_select_lines.png");
    putimage(0, 0, &im_vehicle_select_lines);

    vector<Offer>ret = Manager::GetInstance()->Get_Offers_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Line_id: " + to_string(t.line_id) + "  Vehicle_id: " + to_string(t.vehicle_id);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 439 && x < 697 && y> 493 && y < 577)//跳转到DRAW_VEHICLE_SELECT界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT();
            }
        }
    }
}
IMAGE im_vehicle_select_buses;
void DRAW_VEHICLE_SELECT_BUSES()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_select_buses, "pic/vehicle_select_buses.png");
    putimage(0, 0, &im_vehicle_select_buses);

    vector<Vehicle_Bus>ret = Manager::GetInstance()->Get_Vehicle_Buses_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Vehicle_id: " + to_string(t.vehicle_id) + "  Model:bus" + "  Capacity: " + to_string(t.capacity);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 434 && x < 688 && y> 493 && y < 578)//跳转到DRAW_VEHICLE_SELECT界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT();
            }
        }
    }
}
IMAGE im_vehicle_select_subways;
void DRAW_VEHICLE_SELECT_SUBWAYS()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_vehicle_select_subways, "pic/vehicle_select_subways.png");
    putimage(0, 0, &im_vehicle_select_subways);

    vector<Vehicle_Subway>ret = Manager::GetInstance()->Get_Vehicle_Subways_All();
    int y = 110;
    for (auto& t : ret)
    {
        string text = "Vehicle_id: " + to_string(t.vehicle_id) + "  Model:subway" + "  Capacity: " + to_string(t.capacity) + "  Num_cars:" + to_string(t.num_cars);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 443 && x < 697 && y> 502 && y < 588)//跳转到DRAW_VEHICLE_SELECT界面
            {
                closegraph();
                DRAW_VEHICLE_SELECT();
            }
        }
    }
}
void DRAW_VEHICLE_INSERT()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待插入的车辆信息:", "输入信息", MB_OK);

    TCHAR vehicleid[100];
    InputBox(vehicleid, 100, "vehicle_id", "输入信息", "", xPos, yPos);
    int vehicle_id = atoi(vehicleid);
    CHAR vehiclemodel[100];
    InputBox(vehiclemodel, 100, "model", "输入信息", "", xPos, yPos);
    string vehicle_model(vehiclemodel);
    TCHAR lineid[100];
    InputBox(lineid, 100, "line_id", "输入信息", "", xPos, yPos);
    int line_id = atoi(lineid);

    Vehicle vehicle(vehicle_id, vehicle_model, line_id);
    if (Manager::GetInstance()->Insert_Vehicle(vehicle))
    {
        MessageBox(hwnd, "插入成功", "提示", MB_OK);
    }
}
void DRAW_VEHICLE_UPDATE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的车辆信息:", "输入信息", MB_OK);

    TCHAR vehicleid[100];
    InputBox(vehicleid, 100, "vehicle_id", "输入信息", "", xPos, yPos);
    int vehicle_id = atoi(vehicleid);
    CHAR vehiclemodel[100];
    InputBox(vehiclemodel, 100, "model", "输入信息", "", xPos, yPos);
    string vehicle_model(vehiclemodel);
    CHAR lineid[100];
    InputBox(lineid, 100, "line_id", "输入信息", "", xPos, yPos);
    int line_id = atoi(lineid);

    Vehicle vehicle(vehicle_id, vehicle_model, line_id);
    if (Manager::GetInstance()->Update_Vehicle(vehicle))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
void DRAW_VEHICLE_DELETE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待删除的车辆信息:", "输入信息", MB_OK);

    TCHAR vehicleid[100];
    InputBox(vehicleid, 100, "vehicle_id", "输入信息", "", xPos, yPos);
    int vehicle_id = atoi(vehicleid);

    if (Manager::GetInstance()->Delete_Vehicle(vehicle_id))
    {
        MessageBox(hwnd, "删除成功", "提示", MB_OK);
    }
}

IMAGE im_others_main;
void DRAW_OTHERS_MAIN()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_others_main, "pic/others_main.png");
    putimage(0, 0, &im_others_main);

    // 等待用户输入
    while (true) {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 109 && x < 452 && y> 243 && y < 410)//跳转到OTHERS_PROCEDURE界面
            {
                DRAW_OTHERS_PROCEDURE();
            }
            if (x > 806 && x < 1023 && y> 243 && y < 410)//跳转到OTHERS_VIEW界面
            {
                closegraph();
                DRAW_OTHERS_VIEW();
            }
            if (x > 439 && x < 694 && y> 444 && y < 530)//跳转到LOGIN界面
            {
                closegraph();
                DRAW_LOGIN();
            }
        }
    }
}
void DRAW_OTHERS_PROCEDURE()
{
    int xPos = WIDTH / 2; // X 坐标
    int yPos = HEIGHT / 2; // Y 坐标
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    MessageBox(hwnd, "请输入待更新的城市信息:", "输入信息", MB_OK);

    TCHAR cityid[100];
    InputBox(cityid, 100, "city_id", "输入信息", "", xPos, yPos);
    int city_id = atoi(cityid);
    CHAR citypopulation[100];
    InputBox(citypopulation, 100, "city_population", "输入信息", "", xPos, yPos);
    int city_population = atoi(citypopulation);

    if (Manager::GetInstance()->Update_City1(city_id, city_population))
    {
        MessageBox(hwnd, "更新成功", "提示", MB_OK);
    }
}
IMAGE im_others_view;
void DRAW_OTHERS_VIEW()
{
    initgraph(WIDTH, HEIGHT); // 开设窗口
    HWND hwnd = GetHWnd(); // 获取窗口句柄
    SetWindowPos(hwnd, HWND_TOP, windowX, windowY, WIDTH, HEIGHT, SWP_SHOWWINDOW); // 设置窗口位置和大小
    cleardevice();//清屏
    loadimage(&im_others_view, "pic/others_view.png");
    putimage(0, 0, &im_others_view);

    vector<City_Station_Count>tmp = Manager::GetInstance()->Get_City_Station_Count();
    int y = 110;
    for (const auto& i : tmp)
    {
        string text = "City_id: " + to_string(i.city_id) + "  Station_Count: " + to_string(i.station_count);
        outtextxy(100, y, text.c_str());
        y += 20;
    }

    // 等待用户输入
    while (true)
    {
        MOUSEMSG msg = GetMouseMsg();
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            int x = msg.x;
            int y = msg.y;

            if (x > 433 && x < 685 && y> 496 && y < 580)//跳转到DRAW_OTHERS_MAIN界面
            {
                closegraph();
                DRAW_OTHERS_MAIN();
            }
        }
    }
}
