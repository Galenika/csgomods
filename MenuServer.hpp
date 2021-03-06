#pragma once

#include <iostream>
#include <thread>
#include <set>
#include <filesystem>

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include "jsonxx/jsonxx.h"

#include "GlobalVars.hpp"
#include "Settings.hpp"
#include "Client.hpp"
#include "Engine.hpp"
#include "BaseCombatWeapon.hpp"
#include "Helpers.hpp"
#include "TeamNum.hpp"

#define WEBSOCKET_PORT 2222
#define HTTP_SERVER_PORT 2223
#define HTTP_SERVER_DIRECTORY "./menu/dist"

#define WEBSOCKET_STOP_LISTENING "stop_listening"
#define WEBSOCKET_CLOSE_MENU "close_menu"
#define WEBSOCKET_GET_ALL_SETTINGS "get_all_settings"
#define WEBSOCKET_GET_CONFIGS_LIST "get_configs_list"
#define WEBSOCKET_GET_ACTIVE_WEAPON "get_active_weapon"
#define WEBSOCKET_GET_TEAM "get_team"
#define WEBSOCKET_GET_ALL_SKINS "get_all_skins"
#define WEBSOCKET_GAME_FULL_FORCE_UPDATE "game_full_force_update"

#define WEBSOCKET_UPDATE_SETTINGS "update_settings"
#define WEBSOCKET_LOAD_CONFIG "load_config"
#define WEBSOCKET_SAVE_CONFIG "save_config"
#define WEBSOCKET_DELETE_CONFIG "delete_config"


using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

typedef websocketpp::server<websocketpp::config::asio> Server;
typedef std::set<websocketpp::connection_hdl, std::owner_less<websocketpp::connection_hdl>> connectionsList;

class MenuServer {
private:
  Server server;
  connectionsList connections;

  void onOpen(websocketpp::connection_hdl);
  void onMessage(websocketpp::connection_hdl, Server::message_ptr);
  void onClose(websocketpp::connection_hdl);
  void log(const std::string);

public:
  MenuServer();
  void start();
  void sendMessage(websocketpp::connection_hdl, std::string, jsonxx::Value);
  void sendMessageAll(std::string, jsonxx::Object);
  void getActiveWeapon(int);
  void getTeam(TeamNum);

  void closeMenu(websocketpp::connection_hdl);
  void stopListening(websocketpp::connection_hdl);
  void getAllSettings(websocketpp::connection_hdl);
  void getConfigsList(websocketpp::connection_hdl);
  void getActiveWeapon(websocketpp::connection_hdl);
  void updateSettings(websocketpp::connection_hdl, jsonxx::Object);
  void loadConfig(websocketpp::connection_hdl, jsonxx::Object);
  void saveConfig(websocketpp::connection_hdl, jsonxx::Object);
  void deleteConfig(websocketpp::connection_hdl, jsonxx::Object);
  void gameFullForceUpdate(websocketpp::connection_hdl);
  void getAllSkins(websocketpp::connection_hdl);
  void getTeam(websocketpp::connection_hdl);
};

extern MenuServer menuServer;