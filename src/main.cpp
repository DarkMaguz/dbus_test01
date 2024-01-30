#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

#include <dbus-c++-1/dbus-c++/dbus.h>
#include <dbus-c++-1/dbus-c++/types.h>

#include "DisplayConfig.h"

class DisplayConfig :
		public org::gnome::Mutter::DisplayConfig_proxy,
		public DBus::IntrospectableProxy,
	  public DBus::ObjectProxy
{
	public:
		DisplayConfig(DBus::Connection& connection, const char* path, const char* name) :
			DBus::ObjectProxy(connection, path, name)
		{
		}

		void MonitorsChanged() {
			std::cout << "MonitorsChanged" << std::endl;
		}

	private:
};

int main(int argc, char **argv)
{
	std::cout << "Hello World!" << std::endl;

	DBus::BusDispatcher dispatcher;
	DBus::default_dispatcher = &dispatcher;
	DBus::Connection bus = DBus::Connection::SessionBus();

	auto dc = DisplayConfig(bus, "/org/gnome/Mutter/DisplayConfig", "org.gnome.Mutter.DisplayConfig");

	uint32_t serial;
	std::vector<DBus::Struct<DBus::Struct<std::string, std::string, std::string, std::string>, std::vector<DBus::Struct<std::string, int32_t, int32_t, double, double, std::vector<double>, std::map<std::string, DBus::Variant>>>, std::map<std::string, DBus::Variant>>> monitors;
	std::vector<DBus::Struct<int32_t, int32_t, double, uint32_t, bool, std::vector<DBus::Struct<std::string, std::string, std::string, std::string>>, std::map<std::string, DBus::Variant>>> logical_monitors;
	std::map< std::string, DBus::Variant > properties;

	dc.GetCurrentState(serial, monitors, logical_monitors, properties);

	// for (auto m : monitors)
	// {

	// 	std::cout << "m: " << m << std::endl;
	// }

	return 0;
}
