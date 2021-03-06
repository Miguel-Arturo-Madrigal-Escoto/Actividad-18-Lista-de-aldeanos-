#include "videogame.h"
#include <algorithm>

using namespace std;

VideoGame::VideoGame(){}

void VideoGame::setNombreUsuario(const string& v){
    this->nombre_usuario = v;
}
string VideoGame::getNombreUsuario(){
    return this->nombre_usuario;
}

void VideoGame::agregarCivilizacion(const Civilizacion& c){
    civilizaciones.push_back(c);
}

void VideoGame::encabezado_tabla(){
    cout << left;
    cout << setw(25) << "Nombre civilizacion";
    cout << setw(20) << "Ubicacion en x";
    cout << setw(20) << "Ubicacion en y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
}

void VideoGame::mostrar(){

    encabezado_tabla();

    for(size_t i(0); i < civilizaciones.size(); i++){
        Civilizacion& civ = civilizaciones[i];
        cout << civ;
    }
}

void VideoGame::insertar(const Civilizacion& c, size_t pos){
    civilizaciones.insert(civilizaciones.begin() + pos, c);
}

void VideoGame::inicializar(const Civilizacion& c, size_t n){
    civilizaciones = vector<Civilizacion>(n, c);
}

bool VideoGame::eliminar(const Civilizacion& c){
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return false;
    }else{
        civilizaciones.erase(it);
        return true;
    }
}

Civilizacion VideoGame::primera(){
    return civilizaciones.front();
}

Civilizacion VideoGame::ultima(){
    return civilizaciones.back();
}

Civilizacion* VideoGame::buscar(const Civilizacion& c){
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

void VideoGame::ordenarNombre(){
    sort(civilizaciones.begin(), civilizaciones.end());
}
void VideoGame::ordenarUbicacionX(){
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){ return c1.getUbicacionX() < c2.getUbicacionX();});
}
void VideoGame::ordenarUbicacionY(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){ return c1.getUbicacionY() < c2.getUbicacionY();});
}
void VideoGame::ordenarPuntuacion(){
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){ return c1.getPuntuacion() > c2.getPuntuacion();});
}

size_t VideoGame::total(){
    return civilizaciones.size();
}

VideoGame::~VideoGame(){}


