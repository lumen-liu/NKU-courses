#include "Manager.h"

City::City(){}
City::City(int City_id, int Population, string Name)
{
	this->city_id = City_id;
	this->population = Population;
	this->name = Name;
}

Include::Include(){}
Include::Include(int City_id, int Station_id)
{
	this->city_id = City_id;
	this->station_id = Station_id;
}

Station::Station(){}
Station::Station(int Station_id, string Name, double Latitude, double Longitude, int City_id)
{
	this->station_id = Station_id;
	this->name = Name;
	this->latitude = Latitude;
	this->longitude = Longitude;
	this->city_id = City_id;
}

City_Station_Count::City_Station_Count(){}
City_Station_Count::City_Station_Count(int city_id, int station_count)
{
	this->city_id = city_id;
	this->station_count = station_count;
}


Serve::Serve(){}
Serve::Serve(int Station_id, int Passenger_id)
{
	this->station_id = Station_id;
	this->passenger_id = Passenger_id;
}

Passenger::Passenger(){}
Passenger::Passenger(int Passenger_id, string Name, int Age, string Gender)
{
	this->passenger_id = Passenger_id;
	this->name = Name;
	this->age = Age;
	this->gender = Gender;
}

Setting::Setting(){}
Setting::Setting(int City_id, int Line_id)
{
	this->city_id = City_id;
	this->line_id = Line_id;
}

Line::Line(){}
Line::Line(int Line_id, string Name, int City_id)
{
	this->line_id = Line_id;
	this->name = Name;
	this->city_id = City_id;
}

Offer::Offer(){}
Offer::Offer(int Line_id, int Vehicle_id)
{
	this->line_id = Line_id;
	this->vehicle_id = Vehicle_id;
}

Vehicle::Vehicle(){}
Vehicle::Vehicle(int Vehicle_id, string Model, int Line_id)
{
	this->vehicle_id = Vehicle_id;
	this->model = Model;
	this->line_id = Line_id;
}

Vehicle_Bus::Vehicle_Bus(){}
Vehicle_Bus::Vehicle_Bus(int Vehicle_id, int Capacity)
{
	this->vehicle_id = Vehicle_id;
	this->capacity = Capacity;
}

Vehicle_Subway::Vehicle_Subway(){}
Vehicle_Subway::Vehicle_Subway(int Vehicle_id, int Capacity, int Num_cars)
{
	this->vehicle_id = Vehicle_id;
	this->capacity = Capacity;
	this->num_cars = Num_cars;
}

Manager::Manager()
{
	con = mysql_init(NULL);
	//�����ַ�����
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	//�������ݿ⣬������ʧ���򱨴�
	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database : Error:%s\n", mysql_error(con));
		cout << endl;
		return;
	}
}

Manager::~Manager()
{
	//�Ͽ������ݿ������
	mysql_close(con);
}

//������ݿ�city�����Ƿ��Ѿ��и�City_id�����з���false�����޷���true
bool Check_City_city_id(int City_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE city_id=%d", City_id);
	if (Manager::GetInstance()->Get_Citys_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�station�����Ƿ��Ѿ��и�Station_id��City_id�����з���false�����޷���true
bool Check_Station_station_id_city_id(int Station_id, int City_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE station_id=%d AND city_id=%d", Station_id, City_id);
	if (Manager::GetInstance()->Get_Stations_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�station�����Ƿ��Ѿ��и�Station_id�����з���false�����޷���true
bool Check_Station_station_id(int Station_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE station_id=%d", Station_id);
	if (Manager::GetInstance()->Get_Stations_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�include�����Ƿ��Ѿ��и�City_id��Station_id�����з���false�����޷���true
bool Check_Include_city_id_station_id(int City_id, int Station_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE city_id=%d AND station_id=%d", City_id, Station_id);
	if (Manager::GetInstance()->Get_Includes_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�passenger�����Ƿ��Ѿ��и�Passenger_id�����з���false�����޷���true
bool Check_Passenger_passenger_id(int Passenger_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE passenger_id=%d", Passenger_id);
	if (Manager::GetInstance()->Get_Passengers_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�serve�����Ƿ��Ѿ��и�Station_id��Passenger_id�����з���false�����޷���true
bool Check_Serve_station_id_passenger_id(int Station_id, int Passenger_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE station_id=%d AND passenger_id=%d", Station_id, Passenger_id);
	if (Manager::GetInstance()->Get_Serves_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�line�����Ƿ��Ѿ��и�Line_id��City_id�����з���false�����޷���true
bool Check_Line_line_id_city_id(int Line_id, int City_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE line_id=%d AND city_id=%d", Line_id, City_id);
	if (Manager::GetInstance()->Get_Lines_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�line�����Ƿ��Ѿ��и�Line_id�����з���false�����޷���true
bool Check_Line_line_id(int Line_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE line_id=%d", Line_id);
	if (Manager::GetInstance()->Get_Lines_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�setting�����Ƿ��Ѿ��и�City_id��Line_id�����з���false�����޷���true
bool Check_Setting_city_id_line_id(int City_id, int Line_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE city_id=%d AND line_id=%d", City_id, Line_id);
	if (Manager::GetInstance()->Get_Settings_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�vehicle�����Ƿ��Ѿ��и�Vehicle_id�����з���false�����޷���true
bool Check_Vehicle_vehicle_id(int Vehicle_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE vehicle_id=%d", Vehicle_id);
	if (Manager::GetInstance()->Get_Vehicles_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�offer�����Ƿ��Ѿ��и�Line_id��Vehicle_id�����з���false�����޷���true
bool Check_Offer_line_id_vehicle_id(int Line_id, int Vehicle_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE line_id=%d AND vehicle_id=%d", Line_id, Vehicle_id);
	if (Manager::GetInstance()->Get_Offers_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�bus�����Ƿ��Ѿ��и�Vehicle_Bus_vehicle_id�����з���false�����޷���true
bool Check_Vehicle_Bus_vehicle_id(int Vehicle_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE vehicle_id=%d", Vehicle_id);
	if (Manager::GetInstance()->Get_Vehicle_Buses_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

//������ݿ�subway�����Ƿ��Ѿ��и�Vehicle_Subway_vehicle_id�����з���false�����޷���true
bool Check_Vehicle_Subway_vehicle_id(int Vehicle_id)
{
	char tmp[2000];
	sprintf_s(tmp, "WHERE vehicle_id=%d", Vehicle_id);
	if (Manager::GetInstance()->Get_Vehicle_Subways_All(tmp).size() != 0)
	{
		return false;
	}
	return true;
}

bool Manager::Insert_City(City& city)
{
	//������ݿ�city�����Ƿ��Ѿ��и�city_id�����У��򱨴�˵���޷�����
	if (!Check_City_city_id(city.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_city: Error: the city_id has existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into city (city_id, population, name) values(%d,%d,'%s')",
		city.city_id, city.population, city.name.c_str());
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_city", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_City(City& city)
{
	//������ݿ����Ƿ��иó��е�city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(city.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city: Error: the city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}
	

	char sql[2000];
	sprintf_s(sql, "UPDATE city Set population=%d, name='%s' WHERE city_id = %d", 
		city.population, city.name.c_str(), city.city_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

bool Manager::Update_City1(int city_id, int population)
{
	//������ݿ����Ƿ��иó��е�city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city: Error: the city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE city Set population=%d WHERE city_id = %d",
		population, city_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_City2(int city_id, int population)
{
	//������ݿ����Ƿ��иó��е�city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city: Error: the city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	//char sql1[2000];
	//sprintf_s(sql1, "DELIMITER \\\\  ");
	//mysql_query(con, sql1);
	//char sql2[2000];
	//sprintf_s(sql2, "CREATE PROCEDURE UpdateCityPopulation(IN new_city_id INT, IN new_population INT) \n BEGIN \n UPDATE City SET population = new_population WHERE city_id = new_city_id ; \n END; \\\\ ");
	//mysql_query(con, sql2);
	//char sql3[2000];
	//sprintf_s(sql3, "DELIMITER;");
	//mysql_query(con, sql3);
	//char sql4[2000];
	//sprintf_s(sql4, "CALL UpdateCityPopulation(%d, %d)", city_id, population);

	//delimiter \\
	//	create procedure UpdateCityPopulation(in new_city_id int, in new_population int)
	//	begin
	//	update city set population = new_population where city_id = new_city_id;
	//end; \\
	//delimiter;



	char sql4[2000];
	sprintf_s(sql4, "CALL UpdateCityPopulation(%d, %d)", city_id, population);

	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql4))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_city.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

//����ɾ�� Station Line 
bool Manager::Delete_City(int City_id)
{
	//������ݿ����Ƿ��иó��е�city_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_City_city_id(City_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_city: Error: the city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//����ɾ�� Station��Station ����ɾ�� Include��
	vector <int>tmp1 = Get_Stations_Station_id(City_id);
	int tmp1size = tmp1.size();
	while (tmp1size > 0)
	{
		Manager::GetInstance()->Delete_Station(tmp1[--tmp1size]);
	}
	//����ɾ�� Line��Line ����ɾ�� Setting��
	vector <int>tmp2 = Get_Lines_Line_id(City_id);
	int tmp2size = tmp2.size();
	while (tmp2size > 0)
	{
		Manager::GetInstance()->Delete_Line(tmp2[--tmp2size]);
	}
	

	char sql[2000];
	sprintf_s(sql, "DELETE FROM city WHERE city_id=%d", City_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_city.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<City> Manager::Get_Citys_All(string condition)
{
	vector <City>citylist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM city %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_city.", "������Ϣ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		City city;
		city.city_id = atoi(row[0]);
		city.population = atoi(row[1]);
		city.name = row[2];
		citylist.push_back(city);
	}

	return citylist;
}

vector<City_Station_Count> Manager::Get_City_Station_Count()
{
	vector<City_Station_Count>list;
	char sql1[2000];
	sprintf_s(sql1, "CREATE VIEW Station_Count(city_id, countstations) AS SELECT city_id, COUNT(*) FROM station GROUP BY city_id;");
	mysql_query(con, sql1);
	char sql2[2000];
	sprintf_s(sql2, "SELECT * FROM Station_Count");
	mysql_query(con, sql2);
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		City_Station_Count tmp;
		tmp.city_id = atoi(row[0]);
		tmp.station_count = atoi(row[1]);
		list.push_back(tmp);
	}
	return list;
}

//�������� Include
bool Manager::Insert_Station(Station& station)
{
	//������ݿ����Ƿ��и�station.city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(station.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_station: Error: the station.city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ���station.station_id��station.city_id�����У��򱨴�˵���޷�����
	if (!Check_Station_station_id_city_id(station.station_id, station.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_station: Error: the station.station_id and station.city_id have existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into station (station_id, name, latitude, longitude, city_id) values(%d,'%s',%f,%f,%d)",
		station.station_id, station.name.c_str(), station.latitude, station.longitude, station.city_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_station.", "��ʾ", MB_OK);
		return false;
	}


	//�������� Include
	Include tmp_include(station.city_id, station.station_id);
	Manager::GetInstance()->Insert_Include(tmp_include);


	return true;
}

bool Manager::Update_Station(Station& station)
{
	//������ݿ����Ƿ���station.station_id����û�У��򱨴�˵���޷�����
	if (Check_Station_station_id(station.station_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_station.", "��ʾ", MB_OK);
		return false;
	}

	//Include tmp_include1(Manager::GetInstance()->Get_Stations_City_id(station.station_id), station.station_id);
	//vector<int> tmp_serve_passenger_id = Manager::Get_Serves_Passenger_id(station.station_id);
	//int tmp_serve_passenger_id_size = tmp_serve_passenger_id.size();
	//vector<Serve> tmp_serve;
	//while (tmp_serve_passenger_id_size > 0) 
	//{
	//	tmp_serve[--tmp_serve_passenger_id_size].passenger_id = tmp_serve_passenger_id[tmp_serve_passenger_id_size];
	//	tmp_serve[tmp_serve_passenger_id_size].station_id = station.station_id;
	//}


	char sql[2000];
	sprintf_s(sql, "UPDATE station Set name='%s', latitude=%f, longitude=%f,city_id=%d WHERE station_id = %d",
		station.name.c_str(), station.latitude, station.longitude, station.city_id, station.station_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_station.", "��ʾ", MB_OK);
		return false;
	}


	////�������� Serve Include

	//Include tmp_include2(station.city_id, station.station_id);
	//Manager::GetInstance()->Update_Include(tmp_include1, tmp_include2);

	return true;
}

//����ɾ�� Serve Include
bool Manager::Delete_Station(int Station_id)
{
	//������ݿ����Ƿ���station.station_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Station_station_id(Station_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_station: Error: the Station_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//DELIMITER //

	//	CREATE PROCEDURE DeleteStation(IN stationID INT)
	//	BEGIN
	//	DECLARE EXIT HANDLER FOR SQLEXCEPTION
	//	BEGIN
	//	ROLLBACK;
	//RESIGNAL;
	//END;

	//START TRANSACTION;

	//DELETE FROM Station WHERE station_id = stationID;

	//COMMIT;
	//END //

	//	DELIMITER;


	//����ɾ�� Includee
	Manager::GetInstance()->Delete_Include(Manager::GetInstance()->Get_Stations_City_id(Station_id), Station_id);
	//����ɾ�� Serve
	vector<int>tmp = Manager::GetInstance()->Get_Serves_Passenger_id(Station_id);
	int tmpsize = tmp.size();
	while (tmpsize > 0)
	{
		Manager::GetInstance()->Delete_Serve(Station_id, tmp[--tmpsize]);
	}
	
	char sql[2000];
	//sprintf_s(sql, "DELETE FROM station WHERE station_id=%d", Station_id);
	sprintf_s(sql, "CALL DeleteStation(%d)", Station_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_station.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

vector<Station> Manager::Get_Stations_All(string condition)
{
	vector <Station>stationlist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM station %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_station.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Station station;
		station.station_id = atoi(row[0]);
		station.name = row[1];
		station.latitude = atof(row[2]);
		station.longitude = atof(row[3]);
		station.city_id = atoi(row[4]);
		stationlist.push_back(station);
	}

	return stationlist;
}

int Manager::Get_Stations_City_id(int Station_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT city_id FROM station WHERE station_id = %d", Station_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_station.", "��ʾ", MB_OK);
		return 0;
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row = mysql_fetch_row(res);
	return atoi(row[0]);
}

vector<int> Manager::Get_Stations_Station_id(int City_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT station_id FROM station WHERE city_id = %d", City_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_station.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

bool Manager::Insert_Include(Include& includee)
{
	char sql[2000];
	sprintf_s(sql, "INSERT into include (city_id, station_id) values(%d,%d)",
		includee.city_id, includee.station_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_include.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_Include(Include& includee1, Include& includee2)
{
	//������ݿ����Ƿ���includee1.city_id��includee1.station_id����û�У��򱨴�˵���޷�����
	if (Check_Include_city_id_station_id(includee1.city_id, includee1.station_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_include: Error: the includee1.city_id or includee1.station_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ��и�includee2.city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(includee2.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_include: Error: the includee2.city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ���includee2.station_id��includee2.city_id����û�У��򱨴�˵���޷�����
	if (Check_Station_station_id_city_id(includee2.station_id, includee2.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_include: Error: the includee2.station_id or includee2.city_id does not exist..", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE include Set city_id=%d, station_id=%d WHERE city_id=%d AND station_id = %d",
		includee2.city_id, includee2.station_id, includee1.city_id, includee1.station_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_include.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

bool Manager::Delete_Include(int City_id, int Station_id)
{
	//������ݿ����Ƿ���City_id��Station_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Include_city_id_station_id(City_id, Station_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_include: Error: the City_id or Station_id does not exist.", "��ʾ", MB_OK);
		return false;
	}
	
	char sql[2000];
	sprintf_s(sql, "DELETE FROM include WHERE city_id=%d AND station_id=%d", City_id, Station_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data to the table_include.", "��ʾ", MB_OK);
		return false;
	}
	
	return true;
}

vector<Include> Manager::Get_Includes_All(string condition)
{
	vector <Include>includelist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM include %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data to the table_include.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Include includee;
		includee.city_id = atoi(row[0]);
		includee.station_id = atoi(row[1]);
		includelist.push_back(includee);
	}

	return includelist;
}

bool Manager::Insert_Passenger(Passenger& passenger)
{
	//������ݿ����Ƿ��и�passenger.passenger_id�����У��򱨴�˵���޷�����
	if (!Check_Passenger_passenger_id(passenger.passenger_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_passenger: Error: the passenger.passenger_id has existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into passenger (passenger_id, name, age, gender) values(%d,'%s',%d,'%s')",
		passenger.passenger_id, passenger.name.c_str(), passenger.age, passenger.gender.c_str());
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_passenger.", "��ʾ", MB_OK);
		return false;
	}


	//��������serve
	//Include tmp_include(station.city_id, station.station_id);
	//Manager::GetInstance()->Insert_Include(tmp_include);


	return true;
}

bool Manager::Update_Passenger(Passenger& passenger)
{
	//������ݿ����Ƿ��иó˿͵�passenger_id����û�У��򱨴�˵���޷�����
	if (Check_Passenger_passenger_id(passenger.passenger_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_passenger: Error: the passenger_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "UPDATE passenger Set name='%s', age=%d, gender='%s' WHERE passenger_id = %d",
		passenger.name.c_str(), passenger.age, passenger.gender.c_str(), passenger.passenger_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_passenger.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

bool Manager::Update_Passenger(Passenger& passenger, int oldid)
{
	//������ݿ����Ƿ��иó˿͵�passenger_id����û�У��򱨴�˵���޷�����
	if (Check_Passenger_passenger_id(oldid))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_passenger: Error: the passenger_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "CALL UpdatePassengerAndServe(%d,%d,'%s',%d,'%s')",
		oldid, passenger.passenger_id, passenger.name.c_str(), passenger.age, passenger.gender.c_str());

	Manager::Delete_Passenger(oldid);
	Manager::Insert_Passenger(passenger);
	Serve tmp(101, 1002);
	Manager::Insert_Serve(tmp);


	return true;
}

//����ɾ�� Serve
bool Manager::Delete_Passenger(int Passenger_id)
{
	//������ݿ����Ƿ��иó˿͵�passenger_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Passenger_passenger_id(Passenger_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_passenger: Error: the Passenger_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//����ɾ�� Serve
	vector<int>tmp = Manager::GetInstance()->Get_Serves_Station_id(Passenger_id);
	int tmpsize = tmp.size();
	while (tmpsize > 0)
	{
		Manager::GetInstance()->Delete_Serve(tmp[--tmpsize], Passenger_id);
	}

	char sql[2000];
	sprintf_s(sql, "DELETE FROM passenger WHERE passenger_id=%d", Passenger_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_passenger.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Passenger> Manager::Get_Passengers_All(string condition)
{
	vector <Passenger>passengerlist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM passenger %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_passenger.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Passenger passenger;
		passenger.passenger_id = atoi(row[0]);
		passenger.name = row[1];
		passenger.age = atoi(row[2]);
		passenger.gender = row[3];
		passengerlist.push_back(passenger);
	}

	return passengerlist;
}

bool Manager::Insert_Serve(Serve& serve)
{
	char sql[2000];
	sprintf_s(sql, "INSERT into serve (station_id, passenger_id) values(%d,%d)",
		serve.station_id, serve.passenger_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_serve.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_Serve(Serve& serve1, Serve& serve2)
{
	//������ݿ����Ƿ���serve1.station_id��serve1.passenger_id����û�У��򱨴�˵���޷�����
	if (Check_Serve_station_id_passenger_id(serve1.station_id, serve1.passenger_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_serve: Error: the serve1.station_id or serve1.passenger_id does not exist.", "��ʾ", MB_OK);
		fprintf(stderr, "Failed to UPDATE data to the table_serve: Error: the serve1.station_id or serve1.passenger_id does not exist.");
		cout << endl;
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "UPDATE serve Set station_id=%d, passenger_id=%d WHERE station_id=%d AND passenger_id = %d",
		serve2.station_id, serve2.passenger_id, serve1.station_id, serve1.passenger_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_serve.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

bool Manager::Delete_Serve(int Station_id, int Passenger_id)
{
	//������ݿ����Ƿ���Station_id��Passenger_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Serve_station_id_passenger_id(Station_id, Passenger_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_serve: Error: the Station_id or Passenger_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "DELETE FROM serve WHERE station_id=%d AND passenger_id=%d", Station_id, Passenger_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_serve.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Serve> Manager::Get_Serves_All(string condition)
{
	vector <Serve>servelist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM serve %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_serve.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Serve serve;
		serve.station_id = atoi(row[0]);
		serve.passenger_id = atoi(row[1]);
		servelist.push_back(serve);
	}

	return servelist;
}

vector<int> Manager::Get_Serves_Passenger_id(int Station_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT passenger_id FROM serve WHERE station_id = %d", Station_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_serve.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

vector<int> Manager::Get_Serves_Station_id(int Passenger_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT station_id FROM serve WHERE passenger_id = %d", Passenger_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_serve.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

//�������� Setting
bool Manager::Insert_Line(Line& line)
{
	//������ݿ����Ƿ��и�line.city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(line.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_line: Error: the line.city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ���line.line_id��line.city_id�����У��򱨴�˵���޷�����
	if (!Check_Line_line_id_city_id(line.line_id, line.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_line: Error: the line.line_id and line.city_id have existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into line (line_id, name, city_id) values(%d,'%s',%d)",
		line.line_id, line.name.c_str(), line.city_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_line.", "��ʾ", MB_OK);
		return false;
	}

	//�������� Setting
	Setting tmp_setting(line.city_id, line.line_id);
	Manager::GetInstance()->Insert_Setting(tmp_setting);

	return true;
}

bool Manager::Update_Line(Line& line)
{
	//������ݿ����Ƿ���line.line_id����û�У��򱨴�˵���޷�����
	if (Check_Line_line_id(line.line_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_line: Error: the line.line_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "UPDATE line Set name='%s', city_id=%d WHERE line_id = %d",
		line.name.c_str(), line.city_id, line.line_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_line.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

//����ɾ�� Setting Vehicle��Vehicle ����ɾ�� Offer��
bool Manager::Delete_Line(int Line_id)
{
	//������ݿ����Ƿ���Line_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Line_line_id(Line_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_line: Error: the Line_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//����ɾ�� Setting
	Manager::GetInstance()->Delete_Setting(Manager::GetInstance()->Get_Lines_City_id(Line_id), Line_id);
	//����ɾ�� Vehicle
	vector<int>tmp = Manager::GetInstance()->Get_Vehicles_Vehicle_id(Line_id);
	int tmpsize = tmp.size();
	while (tmpsize > 0)
	{
		Manager::GetInstance()->Delete_Vehicle(tmp[--tmpsize]);
	}


	char sql[2000];
	sprintf_s(sql, "DELETE FROM line WHERE line_id=%d", Line_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_line.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

vector<Line> Manager::Get_Lines_All(string condition)
{
	vector <Line>linelist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM line %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_line.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Line line;
		line.line_id = atoi(row[0]);
		line.name = row[1];
		line.city_id = atoi(row[2]);
		linelist.push_back(line);
	}

	return linelist;
}

int Manager::Get_Lines_City_id(int Line_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT city_id FROM line WHERE line_id = %d", Line_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_line.", "��ʾ", MB_OK);
		return 0;
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row = mysql_fetch_row(res);
	return atoi(row[0]);
}

vector<int> Manager::Get_Lines_Line_id(int City_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT line_id FROM line WHERE city_id = %d", City_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_line.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

bool Manager::Insert_Setting(Setting& setting)
{
	char sql[2000];
	sprintf_s(sql, "INSERT into setting (city_id, line_id) values(%d,%d)",
		setting.city_id, setting.line_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_setting.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_Setting(Setting& setting1, Setting& setting2)
{
	//������ݿ����Ƿ���setting1.city_id��setting1.line_id����û�У��򱨴�˵���޷�����
	if (Check_Setting_city_id_line_id(setting1.city_id, setting1.line_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_setting: Error: the setting1.city_id or setting1.line_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ��и�setting2.city_id����û�У��򱨴�˵���޷�����
	if (Check_City_city_id(setting2.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_setting: Error: the setting2.city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//������ݿ����Ƿ���setting2.line_id��setting2.city_id����û�У��򱨴�˵���޷�����
	if (Check_Line_line_id_city_id(setting2.line_id, setting2.city_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_setting: Error: the setting2.line_id or setting2.city_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE setting Set city_id=%d, line_id=%d WHERE city_id=%d AND line_id = %d",
		setting2.city_id, setting2.line_id, setting1.city_id, setting1.line_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_setting.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

bool Manager::Delete_Setting(int City_id, int Line_id)
{
	//������ݿ����Ƿ���City_id��Line_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Setting_city_id_line_id(City_id, Line_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_setting: Error: the City_id or Line_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "DELETE FROM setting WHERE city_id=%d AND line_id=%d", City_id, Line_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_setting.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Setting> Manager::Get_Settings_All(string condition)
{
	vector <Setting>settinglist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM setting %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_setting.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Setting setting;
		setting.city_id = atoi(row[0]);
		setting.line_id = atoi(row[1]);
		settinglist.push_back(setting);
	}

	return settinglist;
}

//�������� Offer Vehicle_Bus Vehicle_Subway
bool Manager::Insert_Vehicle(Vehicle& vehicle)
{
	//������ݿ����Ƿ��и�vehicle.vehicle_id�����У��򱨴�˵���޷�����
	if (!Check_Vehicle_vehicle_id(vehicle.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_vehicle: Error: the vehicle.vehicle_id has existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into vehicle (vehicle_id, model, line_id) values(%d,'%s',%d)",
		vehicle.vehicle_id, vehicle.model.c_str(), vehicle.line_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_vehicle.", "��ʾ", MB_OK);
		return false;
	}

	//����������bus���������� Vehicle_Bus
	if (vehicle.model == "bus")
	{
		int xPos = 570; // X ����
		int yPos = 300; // Y ����
		CHAR vehiclecapacity[100];
		InputBox(vehiclecapacity, 100, "capacity", "������Ϣ", "", xPos, yPos);
		int vehicle_capacity = atoi(vehiclecapacity);
		Vehicle_Bus tmpvehiclebus(vehicle.vehicle_id, vehicle_capacity);
		Manager::GetInstance()->Insert_Vehicle_Bus(tmpvehiclebus);
	}
	//����������subway���������� Vehicle_Subway
	if (vehicle.model == "subway")
	{
		int xPos = 570; // X ����
		int yPos = 300; // Y ����
		CHAR vehiclecapacity[100];
		InputBox(vehiclecapacity, 100, "capacity", "������Ϣ", "", xPos, yPos);
		int vehicle_capacity = atoi(vehiclecapacity);
		CHAR vehiclenumcars[100];
		InputBox(vehiclenumcars, 100, "capacity", "������Ϣ", "", xPos, yPos);
		int num_cars = atoi(vehiclenumcars);
		Vehicle_Subway tmpvehiclesubway(vehicle.vehicle_id, vehicle_capacity, num_cars);
		Manager::GetInstance()->Insert_Vehicle_Subway(tmpvehiclesubway);
	}


	//�������� Offer
	//Include tmp_include(station.city_id, station.station_id);
	//Manager::GetInstance()->Insert_Include(tmp_include);


	return true;
}

//bool Manager::Insert_Vehicle_Line_id_NULL(Vehicle& vehicle)
//{
//	//������ݿ����Ƿ��и�vehicle.vehicle_id�����У��򱨴�˵���޷�����
//	if (!Check_Vehicle_vehicle_id(vehicle.vehicle_id))
//	{
//		fprintf(stderr, "Failed to INSERT data to the table_vehicle: Error: the vehicle.vehicle_id has existed already.");
//		cout << endl;
//		return false;
//	}
//
//	char sql[2000];
//	sprintf_s(sql, "INSERT into vehicle (vehicle_id, model) values(%d,'%s')",
//		vehicle.vehicle_id, vehicle.model.c_str());
//	//���޷����룬�򱨴��жϳ���
//	if (mysql_query(con, sql))
//	{
//		fprintf(stderr, "Failed to INSERT data to the table_vehicle: Error:%s\n", mysql_error(con));
//		return false;
//	}
//
//
//	//�������� Offer
//	//Include tmp_include(station.city_id, station.station_id);
//	//Manager::GetInstance()->Insert_Include(tmp_include);
//
//
//	return true;
//}

bool Manager::Update_Vehicle(Vehicle& vehicle)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�����
	if (Check_Vehicle_vehicle_id(vehicle.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_vehicle: Error: the vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//��������µ�vehicle_id��Ӧ�ĳ���ģ��Ϊbus��subway������ɾ��Vehicle�������²���
	if (Manager::GetInstance()->Get_Vehicles_Model(vehicle.vehicle_id) == "bus"|| Manager::GetInstance()->Get_Vehicles_Model(vehicle.vehicle_id) == "subway")
	{
		Manager::GetInstance()->Delete_Vehicle(vehicle.vehicle_id);
		Manager::GetInstance()->Insert_Vehicle(vehicle);
		return true;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE vehicle Set model='%s', line_id=%d WHERE vehicle_id = %d",
		vehicle.model.c_str(), vehicle.line_id, vehicle.vehicle_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_vehicle.", "��ʾ", MB_OK);
		return false;
	}

	if (vehicle.model == "bus")
	{
		int xPos = 570; // X ����
		int yPos = 300; // Y ����
		CHAR vehiclecapacity[100];
		InputBox(vehiclecapacity, 100, "capacity", "������Ϣ", "", xPos, yPos);
		int vehicle_capacity = atoi(vehiclecapacity);
		Vehicle_Bus tmpvehiclebus(vehicle.vehicle_id, vehicle_capacity);
		Manager::GetInstance()->Insert_Vehicle_Bus(tmpvehiclebus);
	}
	if (vehicle.model == "subway")
	{
		int xPos = 570; // X ����
		int yPos = 300; // Y ����
		CHAR vehiclecapacity[100];
		InputBox(vehiclecapacity, 100, "capacity", "������Ϣ", "", xPos, yPos);
		int vehicle_capacity = atoi(vehiclecapacity);
		CHAR vehiclenumcars[100];
		InputBox(vehiclenumcars, 100, "num_cars", "������Ϣ", "", xPos, yPos);
		int num_cars = atoi(vehiclenumcars);
		Vehicle_Subway tmpvehiclesubway(vehicle.vehicle_id, vehicle_capacity, num_cars);
		Manager::GetInstance()->Insert_Vehicle_Subway(tmpvehiclesubway);
	}

	return true;
}

//����ɾ�� Offer
bool Manager::Delete_Vehicle(int Vehicle_id)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Vehicle_vehicle_id(Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_vehicle: Error: the Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	//����ɾ�� Offer
	vector<int>tmp = Manager::GetInstance()->Get_Offers_Line_id(Vehicle_id);
	int tmpsize = tmp.size();
	while (tmpsize > 0)
	{
		Manager::GetInstance()->Delete_Offer(tmp[--tmpsize], Vehicle_id);
	}
	//����ɾ�� Vehicle_Bus
	if (Manager::GetInstance()->Get_Vehicles_Model(Vehicle_id) == "bus")
	{
		Manager::GetInstance()->Delete_Vehicle_Bus_From_Vehicle(Vehicle_id);
	}
	//����ɾ�� Vehicle_Subway
	else if (Manager::GetInstance()->Get_Vehicles_Model(Vehicle_id) == "subway")
	{
		Manager::GetInstance()->Delete_Vehicle_Subway_From_Vehicle(Vehicle_id);
	}
	

	char sql[2000];
	sprintf_s(sql, "DELETE FROM vehicle WHERE vehicle_id=%d", Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_vehicle.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Vehicle> Manager::Get_Vehicles_All(string condition)
{
	vector <Vehicle>vehiclelist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM vehicle %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_vehicle.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Vehicle vehicle;
		vehicle.vehicle_id = atoi(row[0]);
		vehicle.model = row[1];
		vehicle.line_id = atoi(row[2]);
		vehiclelist.push_back(vehicle);
	}

	return vehiclelist;
}

vector<int> Manager::Get_Vehicles_Vehicle_id(int Line_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT vehicle_id FROM vehicle WHERE line_id = %d", Line_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_vehicle.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

string Manager::Get_Vehicles_Model(int Vehicle_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT model FROM vehicle WHERE vehicle_id = %d", Vehicle_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_vehicle.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row = mysql_fetch_row(res);

	string ans = row[0];
	return ans;
}

bool Manager::Insert_Offer(Offer& offer)
{
	char sql[2000];
	sprintf_s(sql, "INSERT into offer (line_id, vehicle_id) values(%d,%d)",
		offer.line_id, offer.vehicle_id);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_offer.", "��ʾ", MB_OK);
		return false;
	}
	return true;
}

bool Manager::Update_Offer(Offer& offer1, Offer& offer2)
{
	//������ݿ����Ƿ���offer1.line_id��offer1.vehicle_id����û�У��򱨴�˵���޷�����
	if (Check_Offer_line_id_vehicle_id(offer1.line_id, offer1.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_offer: Error: the offer1.line_id or offer1.vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "UPDATE offer Set line_id=%d, vehicle_id=%d WHERE line_id=%d AND vehicle_id = %d",
		offer2.line_id, offer2.vehicle_id, offer1.line_id, offer1.vehicle_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_offer.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

bool Manager::Delete_Offer(int Line_id, int Vehicle_id)
{
	//������ݿ����Ƿ���Line_id��Vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Offer_line_id_vehicle_id(Line_id, Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_offer: Error: the Line_id or Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "DELETE FROM offer WHERE line_id=%d AND vehicle_id=%d", Line_id, Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_offer.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Offer> Manager::Get_Offers_All(string condition)
{
	vector <Offer>offerlist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM offer %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_offer.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Offer offer;
		offer.line_id = atoi(row[0]);
		offer.vehicle_id = atoi(row[1]);
		offerlist.push_back(offer);
	}

	return offerlist;
}

vector<int> Manager::Get_Offers_Line_id(int Vehicle_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT line_id FROM offer WHERE vehicle_id = %d", Vehicle_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_offer.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

vector<int> Manager::Get_Offers_Vehicle_id(int Line_id)
{
	char sql[2000];
	sprintf_s(sql, "SELECT vehicle_id FROM serve WHERE line_id = %d", Line_id);
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_offer.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	vector<int> ans;
	while ((row = mysql_fetch_row(res)))
	{
		int tmp;
		tmp = atoi(row[0]);
		ans.push_back(tmp);
	}
	return ans;
}

bool Manager::Insert_Vehicle_Bus(Vehicle_Bus& vehicle_bus)
{
	//������ݿ����Ƿ��и�vehicle_bus.vehicle_id�����У��򱨴�˵���޷�����
	if (!Check_Vehicle_Bus_vehicle_id(vehicle_bus.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_bus: Error: the vehicle_bus.vehicle_id has existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into bus (vehicle_id, capacity) values(%d,%d)",
		vehicle_bus.vehicle_id, vehicle_bus.capacity);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_bus.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

bool Manager::Update_Vehicle_Bus(Vehicle_Bus& vehicle_bus)
{
	//������ݿ����Ƿ��иó�����vehicle_bus_id����û�У��򱨴�˵���޷�����
	if (Check_Vehicle_Bus_vehicle_id(vehicle_bus.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_bus: Error: the vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE bus Set capacity=%d WHERE vehicle_id = %d",
		vehicle_bus.capacity, vehicle_bus.vehicle_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_bus.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

//����ɾ�� Vehile
bool Manager::Delete_Vehicle_Bus(int Vehicle_id)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Vehicle_Bus_vehicle_id(Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_bus: Error: the Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "DELETE FROM bus WHERE vehicle_id=%d", Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_bus.", "��ʾ", MB_OK);
		return false;
	}

	//����ɾ�� Vehicle
	//Manager::GetInstance()->Delete_Vehicle(Vehicle_id);

	return true;
}

bool Manager::Delete_Vehicle_Bus_From_Vehicle(int Vehicle_id)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Vehicle_Bus_vehicle_id(Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_bus: Error: the Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "DELETE FROM bus WHERE vehicle_id=%d", Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_bus.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Vehicle_Bus> Manager::Get_Vehicle_Buses_All(string condition)
{
	vector <Vehicle_Bus>vehiclebuslist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM bus %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_bus.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Vehicle_Bus vehicle_bus;
		vehicle_bus.vehicle_id = atoi(row[0]);
		vehicle_bus.capacity = atoi(row[1]);
		vehiclebuslist.push_back(vehicle_bus);
	}

	return vehiclebuslist;
}

//�������� Vehicle
bool Manager::Insert_Vehicle_Subway(Vehicle_Subway& vehicle_subway)
{

	//������ݿ����Ƿ��и�vehicle_subway.vehicle_id�����У��򱨴�˵���޷�����
	if (!Check_Vehicle_Subway_vehicle_id(vehicle_subway.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_subway: Error: the vehicle_subway.vehicle_id has existed already.", "��ʾ", MB_OK);
		return false;
	}

	char sql[2000];
	sprintf_s(sql, "INSERT into subway (vehicle_id, capacity, num_cars) values(%d, %d, %d)",
		vehicle_subway.vehicle_id, vehicle_subway.capacity, vehicle_subway.num_cars);
	//���޷����룬�򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to INSERT data to the table_subway.", "��ʾ", MB_OK);
		return false;
	}


	return true;
}

bool Manager::Update_Vehicle_Subway(Vehicle_Subway& vehicle_subway){
	//������ݿ����Ƿ��иó�����vehicle_subway_id����û�У��򱨴�˵���޷�����
	if (Check_Vehicle_Subway_vehicle_id(vehicle_subway.vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_subway: Error: the vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "UPDATE subway Set capacity=%d, num_cars=%d WHERE vehicle_id = %d",
		vehicle_subway.capacity, vehicle_subway.num_cars, vehicle_subway.vehicle_id);
	//���޷����£��򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to UPDATE data to the table_subway.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

//����ɾ�� Vehile
bool Manager::Delete_Vehicle_Subway(int Vehicle_id)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Vehicle_Subway_vehicle_id(Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_subway: Error: the Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "DELETE FROM subway WHERE vehicle_id=%d", Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_subway.", "��ʾ", MB_OK);
		return false;
	}


	//����ɾ�� Vehicle
	Manager::GetInstance()->Delete_Vehicle(Vehicle_id);

	return true;
}

bool Manager::Delete_Vehicle_Subway_From_Vehicle(int Vehicle_id)
{
	//������ݿ����Ƿ��иó�����vehicle_id����û�У��򱨴�˵���޷�ɾ��
	if (Check_Vehicle_Subway_vehicle_id(Vehicle_id))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_subway: Error: the Vehicle_id does not exist.", "��ʾ", MB_OK);
		return false;
	}


	char sql[2000];
	sprintf_s(sql, "DELETE FROM subway WHERE vehicle_id=%d", Vehicle_id);
	//���޷�ɾ�����򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to DELETE data from the table_subway.", "��ʾ", MB_OK);
		return false;
	}

	return true;
}

vector<Vehicle_Subway> Manager::Get_Vehicle_Subways_All(string condition)
{
	vector <Vehicle_Subway>vehiclesubwaylist;
	char sql[2000];
	sprintf_s(sql, "SELECT * FROM subway %s", condition.c_str());
	//���޷���ѯ���򱨴��жϳ���
	if (mysql_query(con, sql))
	{
		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		MessageBox(hwnd, "Failed to SELETE data from the table_subway.", "��ʾ", MB_OK);
		return {};
	}
	//��ȡ��ѯ���
	MYSQL_RES* res = mysql_store_result(con);
	//����ѯ������沢����
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		Vehicle_Subway vehicle_subway;
		vehicle_subway.vehicle_id = atoi(row[0]);
		vehicle_subway.capacity = atoi(row[1]);
		vehicle_subway.num_cars = atoi(row[2]);
		vehiclesubwaylist.push_back(vehicle_subway);
	}

	return vehiclesubwaylist;
}

