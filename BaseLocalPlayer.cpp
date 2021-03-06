#include "BaseLocalPlayer.hpp"

BaseLocalPlayer::BaseLocalPlayer() {
	this->dwBase = 0;
};

int BaseLocalPlayer::get() {
	//std::cout << "BaseLocalPlayer::get()" << std::endl;
	return mem.Read<int>(clientDll.dwBase + Offsets::signatures::dwLocalPlayer);
}

Vector3 BaseLocalPlayer::m_vecVelocity(){
	auto vec = Vector3(mem.Read<Vec3>(get() + Offsets::netvars::m_vecVelocity));
	//std::cout << "BaseLocalPlayer::m_vecVelocity(): (" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
	return vec;
}

int BaseLocalPlayer::m_iCrosshairId(){
	return mem.Read<int>(get() + Offsets::netvars::m_iCrosshairId);
}