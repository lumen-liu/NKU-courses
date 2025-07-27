#include <mysql.h>
#include <bits/stdc++.h>
#include <easyx.h>
#include <Windows.h>
using namespace std;

class City
{
public:
	int city_id;
	int population;
	string name;
public:
	City();
	City(int City_id, int Population, string Name);
};
class Include
{
public:
	int city_id;
	int station_id;
public:
	Include();
	Include(int City_id, int Station_id);
};
class Station
{
public:
	int station_id;
	string name;
	double latitude;
	double longitude;
	int city_id;
public:
	Station();
	Station(int Station_id, string Name, double Latitude, double Longitude, int City_id);
};
class City_Station_Count
{
public:
	int city_id;
	int station_count;
	City_Station_Count();
	City_Station_Count(int city_id, int station_count);
};
class Serve
{
public:
	int station_id;
	int passenger_id;
public:
	Serve();
	Serve(int Station_id, int Passenger_id);
};
class Passenger
{
public:
	int passenger_id;
	string name;
	int age;
	string gender;
public:
	Passenger();
	Passenger(int Passenger_id, string Name, int Age, string Gender);
};
class Setting
{
public:
	int city_id;
	int line_id;
public:
	Setting();
	Setting(int City_id, int Line_id);
};
class Line
{
public:
	int line_id;
	string name;
	int city_id;
public:
	Line();
	Line(int Line_id, string Name, int City_id);
};
class Offer
{
public:
	int line_id;
	int vehicle_id;
public:
	Offer();
	Offer(int Line_id, int Vehicle_id);
};
class Vehicle
{
public:
	int vehicle_id;
	string model;
	int line_id;
public:
	Vehicle();
	Vehicle(int Vehicle_id, string Model, int Line_id);
};
class Vehicle_Bus
{
public:
	int vehicle_id;
	int capacity;
public:
	Vehicle_Bus();
	Vehicle_Bus(int Vehicle_id, int Capacity);
};
class Vehicle_Subway
{
public:
	int vehicle_id;
	int capacity;
	int num_cars;
public:
	Vehicle_Subway();
	Vehicle_Subway(int Vehicle_id, int Capacity, int Num_cars);
};

class Manager
{
private:
	MYSQL* con;
	const char* host = "127.0.0.1";
	const char* user = "root";
	const char* pw = "LXMliu2002";
	const char* database_name = "urban_traffic_system";
	const int port = 3306;
public:
	Manager();
	~Manager();

	static Manager* GetInstance()
	{
		static Manager Manager;
		return &Manager;
	}
	bool Insert_City(City& city);
	bool Update_City(City& city);
	bool Update_City1(int city_id, int population);
	bool Update_City2(int city_id, int population);
	bool Delete_City(int City_id);
	vector<City>Get_Citys_All(string condition = "");
	vector<City_Station_Count> Get_City_Station_Count();

	bool Insert_Station(Station& station);
	bool Update_Station(Station& station);
	bool Delete_Station(int Station_id);
	vector<Station>Get_Stations_All(string condition = "");
	int Get_Stations_City_id(int Station_id);
	vector<int> Get_Stations_Station_id(int City_id);

	bool Insert_Include(Include& includee);
	bool Update_Include(Include& includee1, Include& includee2);
	bool Delete_Include(int City_id, int Station_id);
	vector<Include>Get_Includes_All(string condition = "");

	bool Insert_Passenger(Passenger& passenger);
	bool Update_Passenger(Passenger& passenger);
	bool Update_Passenger(Passenger& passenger, int oidid);
	bool Delete_Passenger(int Passenger_id);
	vector<Passenger>Get_Passengers_All(string condition = "");

	bool Insert_Serve(Serve& serve);
	bool Update_Serve(Serve& serve1, Serve& serve2);
	bool Delete_Serve(int Station_id, int Passenger_id);
	vector<Serve>Get_Serves_All(string condition = "");
	vector<int> Get_Serves_Passenger_id(int Station_id);
	vector<int> Get_Serves_Station_id(int Passenger_id);

	bool Insert_Line(Line& line);
	bool Update_Line(Line& line);
	bool Delete_Line(int Line_id);
	vector<Line>Get_Lines_All(string condition = "");
	int Get_Lines_City_id(int Line_id);
	vector<int> Get_Lines_Line_id(int City_id);

	bool Insert_Setting(Setting& setting);
	bool Update_Setting(Setting& setting1, Setting& setting2);
	bool Delete_Setting(int Line_id, int City_id);
	vector<Setting>Get_Settings_All(string condition = "");

	bool Insert_Vehicle(Vehicle& vehicle);
	//bool Insert_Vehicle_Line_id_NULL(Vehicle& vehicle);
	bool Update_Vehicle(Vehicle& vehicle);
	bool Delete_Vehicle(int Vehicle_id);
	vector<Vehicle>Get_Vehicles_All(string condition = "");
	vector<int> Get_Vehicles_Vehicle_id(int Line_id);

	bool Insert_Offer(Offer& offer);
	bool Update_Offer(Offer& offer1, Offer& offer2);
	bool Delete_Offer(int Line_id, int Vehicle_id);
	vector<Offer>Get_Offers_All(string condition = "");
	vector<int> Get_Offers_Line_id(int Station_id);
	vector<int> Get_Offers_Vehicle_id(int Line_id);

	bool Insert_Vehicle_Bus(Vehicle_Bus& vehicle_bus);
	bool Update_Vehicle_Bus(Vehicle_Bus& vehicle_bus);
	bool Delete_Vehicle_Bus(int Vehicle_id);
	bool Delete_Vehicle_Bus_From_Vehicle(int Vehicle_id);
	vector<Vehicle_Bus>Get_Vehicle_Buses_All(string condition = "");
	string Get_Vehicles_Model(int Vehicle_id);

	bool Insert_Vehicle_Subway(Vehicle_Subway& vehicle_subway);
	bool Update_Vehicle_Subway(Vehicle_Subway& vehicle_subway);
	bool Delete_Vehicle_Subway(int Vehicle_id);
	bool Delete_Vehicle_Subway_From_Vehicle(int Vehicle_id);
	vector<Vehicle_Subway>Get_Vehicle_Subways_All(string condition = "");

};

