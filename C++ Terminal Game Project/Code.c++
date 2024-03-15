//Librerias, usings, etc
#include <iostream>
// #include <conio.h>
#include <curses.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Prototipos de funciones
void menuPrincipal();
void opcion_1();
void opcion_2();

//Clases
class Personaje {
private:
    string nombre;
    string tipo; //los tipos determinan las acciones que va a poder llevar a cabo el personaje
                 //el tipo puede ser "CABALLERO" (orientado a ataques fisicos), "MAGO BLANCO" (orientado a tareas de support) y "MAGO OSCURO" (orientado a ataques magicos)
    int dannoFisico;
    int dannoMagico;
    int vidaMaxima;
    int magiaMaxima;
    int vida;
    int magia;

public:
    //Constructores
    Personaje () {
        this->nombre = " ";
        this->tipo = " ";
        this->dannoFisico = 0;
        this->dannoMagico = 0;
        this->vidaMaxima = 0;
        this->magiaMaxima = 0;
        this->vida = 0;
        this->magia = 0;
    }

    Personaje (string _nombre, string _tipo, int _dannofisico, int _dannoMagico, int _vidaMaxima, int _magiaMaxima) { 
        this->nombre = _nombre;
        this->tipo = _tipo;
        this->dannoFisico = _dannofisico;
        this->dannoMagico = _dannoMagico;
        this->vidaMaxima = _vidaMaxima;
        this->magiaMaxima = _magiaMaxima;  
        this->vida = _vidaMaxima;
        this->magia = _magiaMaxima;
    }

    //setter general
    void crearPersonaje (string _nombre, string _tipo, int _dannofisico, int _dannoMagico, int _vidaMaxima, int _magiaMaxima) { 
        this->nombre = _nombre;
        this->tipo = _tipo;
        this->dannoFisico = _dannofisico;
        this->dannoMagico = _dannoMagico;
        this->vidaMaxima = _vidaMaxima;
        this->magiaMaxima = _magiaMaxima;
        this->vida = _vidaMaxima;
        this->magia = _magiaMaxima;
    }

    //Getters y setters
    string getNombre () {
        return this->nombre;
    }
    void setNombre (string _nombre) {
        this->nombre = _nombre;
    }
    string getTipo () {
        return this->tipo;
    }
    void setTipo (string _tipo) {
        this->tipo = _tipo;
    }
    int getDannoFisico () {
        return this->dannoFisico;
    }
    void setDannoFisico (int _dannoFisico) {
        this->dannoFisico = _dannoFisico;
    }
    int getDannoMagico () {
        return this->dannoMagico;
    }
    void setDannoMagico (int _dannoMagico) {
        this->dannoMagico = _dannoMagico;
    }
    int getVidaMaxima () {
        return this->vidaMaxima;
    }
    void setVidaMaxima (int _vidaMaxima) {
        this->vidaMaxima = _vidaMaxima;
    }
    int getMagiaMaxima () {
        return this->magiaMaxima;
    }
    void setMagiaMaxima (int _magiaMaxima) {
        this->magiaMaxima = _magiaMaxima;
    }
    int getVida () {
        return this->vida;
    }
    void setVida (int _vida) {
        this->vida = _vida;
    }
    int getMagia () {
        return this->magia;
    }
    void setMagia (int _magia) {
        this->magia = _magia;
    }

    //acciones en combate
    void ataqueFisico (Personaje &personaje) { //hace danno fisico al rival (todos los personajes, los magos haran muy poco danno fisico)
        system("clear");

        if (personaje.getTipo() == "MAGO BLANCO" || personaje.getTipo() == "MAGO OSCURO" || personaje.getTipo() == "ENEMIGO") {
            personaje.setVida(personaje.getVida() - this->dannoFisico);
            cout<<this->nombre<<" LE HIZO "<<this->dannoFisico<<" DE DANNO FISICO A "<<personaje.getNombre()<<endl<<endl;
        }
        else {
            personaje.setVida(personaje.getVida() - (this->dannoFisico * 0.75));
            cout<<this->nombre<<" LE HIZO "<<(this->dannoFisico * 0.75)<<" DE DANNO FISICO A "<<personaje.getNombre()<<endl<<endl;
        }

        system("PAUSE");
    }

    void ataqueMagico (Personaje &personaje) { //hace danno magico al rival (solo magos oscuros)
        system("clear");
        if (this->magia >= 100) {
            this->magia -= 100;

            if (personaje.getTipo() == "CABALLERO" || personaje.getTipo() == "ENEMIGO") {
                personaje.setVida(personaje.getVida() - this->dannoMagico);
                cout<<this->nombre<<" LE HIZO "<<this->dannoMagico<<" DE DANNO MAGICO A "<<personaje.getNombre()<<endl<<endl;
            }
            else {
                personaje.setVida(personaje.getVida() - (this->dannoMagico * 0.75));
                cout<<this->nombre<<" LE HIZO "<<(this->dannoMagico * 0.75)<<" DE DANNO MAGICO A "<<personaje.getNombre()<<endl<<endl;
            }   
        }
        else {
            cout<<this->nombre<<" NO TIENE LOS SUFICIENTES PUNTOS MAGICOS PARA REALIZAR ESTA ACCION\n\n";
        }
        system("PAUSE");
    }

    void curarAliado (Personaje &personaje) { //annade vida a un aliado a cambio de puntos magicos (solo los magos blancos)
        system("clear");
        if (this->magia >= 100) {
            this->magia -= 100;
            if (personaje.getVida() + 100 > personaje.getVidaMaxima())
                personaje.setVida(personaje.getVidaMaxima());
            else
                personaje.setVida(personaje.getVida() + 100);
            cout<<this->nombre<<" CURO A "<<personaje.getNombre()<<endl<<endl;
        }
        else {
            cout<<this->nombre<<" NO TIENE LOS SUFICIENTES PUNTOS MAGICOS PARA REALIZAR ESTA ACCION\n\n";
        }
        system("PAUSE");
    }

    void darMagiaAliado (Personaje &personaje) { //annade puntos magicos a un aliado a cambio de puntos magicos (solo los magos blancos)
        system("clear");
        if (this->magia >= 100) {
            this->magia -= 100;
            if (personaje.getMagia() + 100 > personaje.getMagiaMaxima())
                personaje.setMagia(personaje.getMagiaMaxima());
            else
                personaje.setMagia(personaje.getMagia() + 100);
            cout<<this->nombre<<" DIO PUNTOS MAGICOS A "<<personaje.getNombre()<<endl<<endl;
        }
        else {
            cout<<this->nombre<<" NO TIENE LOS SUFICIENTES PUNTOS MAGICOS PARA REALIZAR ESTA ACCION\n\n";
        }
        system("PAUSE");
    }
};

class PersonajeParty: public Personaje{
private:
    int puesto; //Esta variable determina el puesto del personaje en comabate, dentro de cada combate pueden haber tres personajes
                //esto significa que si el personaje esta activo, esta variable tendra el valor de 1, 2 o 3 dependiendo su puesto.
                //Si un personaje muere en combate, su puesto que desabilitado y la unica forma de rehabilitarlo es aplicando una cola de fenix a ese personaje
public:
    PersonajeParty () : Personaje () {
        this->puesto = 0;
    }

    int getPuesto () {
        return this->puesto;
    }
    void setPuesto (int _puesto) {
        this->puesto = _puesto;
    }
};

class PersonajeEnemigo: public Personaje {
public:
    PersonajeEnemigo () : Personaje () {
        
    }

    //Estas funciones sirven para asignar valores especificos a los enemigos dependiendo el piso en el que se encuentre
    void setEnemigo (int piso) {  
        switch (piso) {
            case 1: this->crearPersonaje("SLIME", "ENEMIGO", 50, 70, 200, 999999999);
                    break;

            case 2: this->crearPersonaje("FANTASMA", "ENEMIGO", 100, 110, 300, 999999999);
                    break;

            case 3: this->crearPersonaje("MOMIA", "ENEMIGO", 150, 150, 400, 999999999);
                    break;

            case 4: this->crearPersonaje("ESQUELETO", "ENEMIGO", 200, 500, 800, 999999999);
                    break;

            case 5: this->crearPersonaje("GOLEM", "ENEMIGO", 250, 300, 600, 999999999);
                    break;

            default: cout<<"ERROR: EL PISO INTRODUCIDO COMO PARAMETRO DE LA FUNCION NO ES CORRECTO\n\n";
                     system("PAUSE");
                     exit(EXIT_SUCCESS);
                     break;
        }
    }

    void setJefe (int piso) {
        switch (piso) {
            case 1: this->crearPersonaje("DIABABA", "ENEMIGO", 200, 150, 400, 999999999);
                    break;

            case 2: this->crearPersonaje("FYRUS", "ENEMIGO", 100, 300, 550, 999999999);
                    break;

            case 3: this->crearPersonaje("MORPHEEL", "ENEMIGO", 350, 350, 650, 999999999);
                    break;

            case 4: this->crearPersonaje("STALLORD", "ENEMIGO", 400, 500, 800, 999999999);
                    break;

            case 5: this->crearPersonaje("ARGOROK", "ENEMIGO", 500, 550, 1000, 999999999);
                    break;

            default: cout<<"ERROR: EL PISO INTRODUCIDO COMO PARAMETRO DE LA FUNCION NO ES CORRECTO\n\n";
                     system("PAUSE");
                     exit(EXIT_SUCCESS);
                     break;
        }
    }

    void generarAccion (PersonajeParty personajeParty[5], int posicionesPersonajesParty[3]) {
        int personajeObjetivo; //Esta variable almacenara la posicion dentro del combate donde se encuentra el personaje objetivo.

        do { //Elijo al objetivo aleatoriamente y si este esta muerto, elijo otro.
            personajeObjetivo = rand()%(3-0 + 0);
        } while (personajeParty[posicionesPersonajesParty[personajeObjetivo]].getVida() <= 0);

        for (int i=0; i<3; i++) { //En caso de que uno de los personajes de la party tenga su vida por debajo del %30, este personaje sera el nuevo objetivo.
            if (personajeParty[posicionesPersonajesParty[i]].getVida() < personajeParty[posicionesPersonajesParty[i]].getVidaMaxima() * 0.30
                && personajeParty[posicionesPersonajesParty[i]].getVida() > 0) { 
                personajeObjetivo = i; 
                break;
            }
        }

        if ((rand()%(2-0 + 0)) == 1) //Decido aleatoriamente si el ataque que se realizara sera de tipo fisico o magico.
            this->ataqueFisico(personajeParty[posicionesPersonajesParty[personajeObjetivo]]);
        else 
            this->ataqueMagico(personajeParty[posicionesPersonajesParty[personajeObjetivo]]);
    }
};

class Items {
private:
    int pocionVida; //Estas variables representan la cantidad de Items que tiene el jugador
    int pocionMagia;
    int colaDeFenix;

public:
    Items () {
        this->pocionVida = 0;
        this->pocionMagia = 0;
        this->colaDeFenix = 0;
    }

    int getPocionVida () {
        return this->pocionVida;
    }
    void setPocionVida (int _pocionVida) {
        this->pocionVida = _pocionVida;
    }
    int getPocionMagia () {
        return this->pocionMagia;
    }
    void setPocionMagia (int _pocionMagia) {
        this->pocionMagia = _pocionMagia;
    }
    int getColaDeFenix () {
        return this->colaDeFenix;
    }
    void setColaDeFenix (int _colaDeFenix) {
        this->colaDeFenix = _colaDeFenix;
    }

    void usarPocionVida (PersonajeParty &personaje) {
        if (this->pocionVida > 0 && personaje.getVida() > 0) {
            this->pocionVida--;
            
            if (personaje.getVida() + 300 >= personaje.getVidaMaxima())
                personaje.setVida(personaje.getVidaMaxima());
            else
                personaje.setVida(personaje.getVida() + 300);
        }
    }
    
    void usarPocionMagia (PersonajeParty &personaje) {
        if (this->pocionMagia > 0 && personaje.getVida() > 0) {
            this->pocionMagia--;

            if (personaje.getMagia() + 300 >= personaje.getMagiaMaxima())
                personaje.setMagia(personaje.getMagiaMaxima());
            else
                personaje.setMagia(personaje.getMagia() + 300);
        }
    }

    void usarColaDeFenix (PersonajeParty &personaje) {
        if (this->colaDeFenix > 0 && personaje.getVida() == 0) {
            this->colaDeFenix--;
            personaje.setVida(personaje.getVidaMaxima());
        }
    }

    void menuInventario (PersonajeParty personaje[5]) {
        int opcion;

        do {
            system("clear");
            cout<<"POCION DE VIDA: "<<this->pocionVida;
            cout<<"\nPOCION DE MAGIA: "<<this->pocionMagia;
            cout<<"\nCOLA DE FENIX: "<<this->colaDeFenix;
            cout<<"\n\n1. Usar pocion de vida\n";
            cout<<"2. Usar pocion de magia\n";
            cout<<"3. Usar cola de fenix\n";
            cout<<"4. Cambiar posiciones de los personajes en combate\n";
            cout<<"5. Salir\n\n";
            cin>>opcion;

            system("clear");
            switch (opcion) {
                case 1: system("clear");
                        opcionInventario1(personaje);
                        break;
            
                case 2: system("clear");
                        opcionInventario2(personaje);
                        break;
            
                case 3: system("clear");
                        opcionInventario3(personaje);
                        break;
            
                case 4: system("clear");
                        opcionInventario4(personaje);
                        break;

                case 5: break;

                default: system("clear"); 
                         cout<<"OPCION INVALIDA\n\n";
                         system("PAUSE");
                         break;
            }
        } while (opcion != 5);
    
    }

    void opcionInventario1 (PersonajeParty personaje[5]) {
        int opcion;

        cout<<"PERSONAJE CON EL QUE SE VA A USAR ESTE ITEM:\n\n";
        for (int i=0; i<5; i++) 
            cout<<i+1<<". "<<personaje[i].getNombre()<<endl;
        
        cout<<"\nNUMERO DEL PERSONAJE: ";
        cin>>opcion;
        
        if ((personaje[opcion-1].getNombre() == " ") || (opcion < 1 || opcion > 5)) { //si la opcion introducida es invalida 
            cout<<"ESTA OPCION NO CORRESPONDE A NINGUN PERSONAJE\n\n";
        }
        else if (personaje[opcion-1].getVida() == 0) { //si el personaje esta muerto 
            cout<<"ESTE PERSONAJE ESTA MUERTO\n\n";
        }
        else if (this->pocionVida == 0) { //si el inventario no contiene este item 
            cout<<"NO HAY POCIONES DE VIDA EN EL INVENTARIO\n\n";
        }
        else { //si se puede utilizar el item
            this->usarPocionVida(personaje[opcion-1]);
            cout<<"POCION DE VIDA UTILIZADA CON "<<personaje[opcion-1].getNombre()<<endl<<endl;
        }

        system("PAUSE");
    }

    void opcionInventario2 (PersonajeParty personaje[5]) {
        int opcion;

        cout<<"PERSONAJE CON EL QUE SE VA A USAR ESTE ITEM:\n\n";
        for (int i=0; i<5; i++) 
            cout<<i+1<<". "<<personaje[i].getNombre()<<endl;
        
        cout<<"\nNUMERO DEL PERSONAJE: ";
        cin>>opcion;

        if ((personaje[opcion-1].getNombre() == " ") || (opcion < 1 || opcion > 5)) { //si la opcion introducida es invalida
            cout<<"ESTA OPCION NO CORRESPONDE A NINGUN PERSONAJE\n\n";
        }
        else if (personaje[opcion-1].getVida() == 0) { //si el personaje esta muerto
            cout<<"ESTE PERSONAJE ESTA MUERTO\n\n";
        }
        else if (this->pocionMagia == 0) { //si el inventario no contiene este item
            cout<<"NO HAY POCIONES DE MAGIA EN EL INVENTARIO\n\n";
        }
        else { //si se puede utilizar el item
            this->usarPocionMagia(personaje[opcion-1]);
            cout<<"POCION DE MAGIA UTILIZADA UTILIZADA CON "<<personaje[opcion-1].getNombre()<<endl<<endl;
        }

        system("PAUSE");
    }

    void opcionInventario3 (PersonajeParty personaje[5]) {
        int opcion;
        
        cout<<"PERSONAJE CON EL QUE SE VA A USAR ESTE ITEM:\n\n";
        for (int i=0; i<5; i++) 
            cout<<i+1<<". "<<personaje[i].getNombre()<<endl;

        cout<<"\nNUMERO DEL PERSONAJE: ";
        cin>>opcion;

        if ((personaje[opcion-1].getNombre() == " ") || (opcion < 1 || opcion > 5)) { //si la opcion introducida es invalida
            cout<<"ESTA OPCION NO CORRESPONDE A NINGUN PERSONAJE\n\n";
        }
        else if (personaje[opcion-1].getVida() > 0) { //si el personaje esta vivo
            cout<<"ESTE PERSONAJE NO ESTA MUERTO\n\n";
        }
        else if (this->colaDeFenix == 0) { //si el inventario no contiene este item
            cout<<"NO HAY COLAS DE FENIX EN EL INVENTARIO\n\n";
        }
        else { //si se puede utilizar el item
            this->usarColaDeFenix(personaje[opcion-1]);
            cout<<"COLA DE FENIX UTILIZADA CON "<<personaje[opcion-1].getNombre()<<endl<<endl;
        }

        system("PAUSE");
    }

    void opcionInventario4 (PersonajeParty personaje[5]) {
        int puesto, personajeRemplazo;
        int cont = 0;

        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (personaje[j].getPuesto() == cont+1) {
                    cout<<personaje[j].getPuesto()<<". "<<personaje[j].getNombre()<<endl;
                    cont++;
                    break;
                }
            }
        }

        cout<<"\nLugar a remplazar: ";
        cin>>puesto;
        cout<<"Personaje: ";
        cin>>personajeRemplazo;

        if (puesto < 1 || puesto > cont || personajeRemplazo < 1 || personajeRemplazo > cont || puesto == personajeRemplazo) {
            cout<<"\nLAS POSICIONES INTRODUCIDAS NO SON VALIDAS\n\n";
        }
        else {
            int posicionA, posicionB;

            for (int i=0; i<5; i++) {
                if (personaje[i].getPuesto() == puesto)
                    posicionA = i;
                else if (personaje[i].getPuesto() == personajeRemplazo)
                    posicionB = i;
            }

            if (personaje[posicionA].getVida() > 0 || personaje[posicionB].getVida() > 0) {
                personaje[posicionA].setPuesto(personajeRemplazo);
                personaje[posicionB].setPuesto(puesto);
            }
            else {
                cout<<"EL CAMBIO NO PUEDE SER POSIBLE YA QUE UNO DE LOS PERSONAJES ESTA MUERTO\n\n";
            }

            cout<<"\nPOSICIONES ESTABLECIDAS CON EXITO\n\n";
        }

        system("PAUSE");
    }
};

class Pozo { //Los pozos serian las 'x' y cada una de estas es de un distinto tipo 
private:
    int posicionX, posicionY; //Donde esta ubicada la x dentro del piso (la matriz)
    string tipo; //Determina si la X lleva a una lucha contra enemigos, un item, un personaje o a una salida
                 //esta string debe contener como valor: "enemigos", "items", "jefe_salida" o "personaje_party"
    bool estado; //Esta variable determina si la x ya fue accedida por el usuario, si fue asi false, por el contrario true 

public:
    Pozo () {
        this->estado = true;
    }

    int getPosicionX () {
        return this->posicionX;
    }
    void setPosicionX (int _posicionX) {
        this->posicionX = _posicionX;
    }
    int getPosicionY () {
        return this->posicionY;
    }
    void setPosicionY (int _posicionY) {
        this->posicionY = _posicionY;
    }
    string getTipo () {
        return this->tipo;
    }
    void setTipo (string _tipo) {
        this->tipo = _tipo;
    }
    bool getEstado () {
        return this->estado;
    }
    void setEstado (bool _estado) {
        this->estado = _estado;
    }

    void ejecutarPozo (PersonajeParty personajeParty[5] ,Items &items, int &piso) { //Este metodo sirve para ejecutar la accion correspondiente al tipo del pozo
        if (this->tipo == "enemigos")
            this->accionEnemigos(personajeParty, items, piso);

        else if (this->tipo == "items")
            this->accionItem(items);
        
        else if (this->tipo == "jefe_salida")
            this->accionJefe_salida(personajeParty, items, piso);
        
        else if (this->tipo == "personaje_party")
            this->accionPersonajeParty(personajeParty, piso);
    }

    void accionEnemigos (PersonajeParty personajeParty[5], Items &items, int piso) { //Esta accion llevara al jugador a un combate contra un grupo de enemigos
        PersonajeEnemigo personajeEnemigo[3]; //Declaro el array del grupo de enemigos

        for (int i=0; i<3; i++) //Establezco los valores de los atributos de los enemigos segun su piso
            personajeEnemigo[i].setEnemigo(piso);

        if (menuCombate(personajeParty, personajeEnemigo, items) == true) { //Ejecuto el menu del combate y si el jugador pierde... 
            system("clear");
            cout<<"COMBATE GANADO\n\n";
            system("PAUSE");
        }
        else {
            system("clear");
            cout<<"PARTIDA TERMINADA, PERDISTE\n\n";
            system("PAUSE");
            exit(EXIT_SUCCESS);
        }
    }

    void accionItem (Items &items) { //Esta accion dara uno o mas items aleatorios al jugador
        int aux = rand()%(100-1 + 1) + 1;

        system("clear");
        if (aux >= 1 && aux <= 30) {
            items.setPocionVida(items.getPocionVida()+3);
            cout<<"Encontraste 3 pociones de vida\n\n";
        }
        else if (aux >= 31 && aux <= 60) {
            items.setPocionMagia(items.getPocionMagia()+3);
            cout<<"Encontraste 3 pociones de magia\n\n";
        }
        else if (aux >=61 && aux <= 100) {
            items.setColaDeFenix(items.getColaDeFenix()+1);
            cout<<"Encontraste 1 cola de fenix\n\n";
        }
        system("PAUSE");
    }

    void accionJefe_salida (PersonajeParty personajeParty[5], Items &items, int &piso) { //Esta accion llevara a un combate contra un jefe del cual el jugador puede escapar tanto antes de empezarlo como despues de terminarlo para seguir en el piso. 
        int opcion;

        do { //Pregunto al usuario si quiere pelear contra el jefe para pasar al siguiente piso o quiere volver al piso en el que se encuentra
            system("clear");
            cout<<"1. PELEAR CONTRA EL JEFE\n";
            cout<<"2. VOLVER AL PISO\n\n";
            cout<<"OPCION: ";

            cin>>opcion;

            if (opcion == 1)
                break;
            else if (opcion == 2)
                return;
            else
                cout<<"LA OPCION INTRODUCIDA ES INVALIDA\n\n";

        } while (opcion != 1);
        
        PersonajeEnemigo jefe[3]; //Desclaro el array que contendra al jefe (debe ser un array para poder enviarlo como parametro en el metodo menuCombate)

        jefe[0].setJefe(piso); //El jefe estara solo contenido en la posicion [0]

        if (menuCombate(personajeParty, jefe, items) == true) { //Ejecuto el menu del combate y si el jugador pierde... 
            system("clear");
            cout<<"COBATE GANADO\n\n";
            piso++;
            system("PAUSE");
        }
        else {
            system("clear");
            cout<<"PARTIDA TERMINADA, PERDISTE\n\n";
            system("PAUSE");
            exit(EXIT_SUCCESS);
        }
    }

    void accionPersonajeParty (PersonajeParty personajeParty[5], int piso) { //Esta accion le brindara al jugador un nuevo personaje a su party
        system("clear");

        if (piso == 2) {
            personajeParty[3].crearPersonaje("AERIS", "MAGO BLANCO", 10, 0, 700, 1000);
            personajeParty[3].setPuesto(4);
            cout<<"SE HA INTEGRADO "<<personajeParty[3].getNombre()<<" A LA PARTY (TIPO: "<<personajeParty[3].getTipo()<<")\n\n";
        }
        else if (piso == 4) {
            personajeParty[4].crearPersonaje("NOCTIS", "CABALLERO", 200, 0, 1500, 500);
            personajeParty[4].setPuesto(5);
            cout<<"SE HA INTEGRADO "<<personajeParty[4].getNombre()<<" A LA PARTY (TIPO: "<<personajeParty[4].getTipo()<<")\n\n";
        }

        system("PAUSE");
    }

    bool menuCombate (PersonajeParty personajeParty[5], PersonajeEnemigo personajeEnemigo[3], Items &items) {
        int personajePosicion[3]; //Este array contiene el orden de los personajes en combate, el personaje dentro de [0] seria el que esta en la posicion 1, el que esta en [1] es el que esta en la posicion 2 y asi.
        int aux = 1;

        for (int i=0; i<3; i++) { //Establezco que personajes entran en combate.
            for (int j=0; j<5; j++) {
                if (personajeParty[j].getPuesto() == aux) {
                    personajePosicion[i] = j;
                    aux++;
                    break;
                }
            }
        }

        do { //Ejecuto los metodos para el combate
            for (int i=0; i<3; i++) {
                if (personajeParty[personajePosicion[i]].getVida() > 0)
                    menuPersonajeParty(personajeParty, personajePosicion, i, personajeEnemigo, items);
                
                if (verificarVida(personajeEnemigo) == false) //Verifico la vida de los enemigos 
                    return true;
            }

            for (int i=0; i<3; i++) {
                if (personajeEnemigo[i].getVida() > 0)
                    personajeEnemigo[i].generarAccion(personajeParty, personajePosicion);

                if (verificarVida(personajeParty, personajePosicion) == false) //Verifico la vida de la party
                    return false;
            }
        } while (true);

    }

    void menuPersonajeParty (PersonajeParty personajeParty[5], int personajePosicion[3], int personajeAccion, PersonajeEnemigo personajeEnemigo[3], Items &items) {
        //El parametro personajeAccion determina que personaje realizara la accion asignada en el menu, se almacena que personaje almacenado dentro del array personajePosicion debe realizar la accion
        int opcion;

        system("clear");

        for (int i=0; i<3; i++) {
            if (personajeEnemigo[i].getVida() > 0) {
                cout<<i+1<<". "<<personajeEnemigo[i].getNombre()<<":\n";
                cout<<"VIDA: "<<personajeEnemigo[i].getVida()<<" / "<<personajeEnemigo[i].getVidaMaxima()<<endl;
            }
        }

        cout<<endl;

        for (int i=0; i<3; i++) {
            cout<<personajeParty[personajePosicion[i]].getNombre()<<":\n";
            if (personajeParty[personajePosicion[i]].getVida() > 0) {
                cout<<"\tVIDA: "<<personajeParty[personajePosicion[i]].getVida()<<" / "<<personajeParty[personajePosicion[i]].getVidaMaxima()<<endl;
                cout<<"\tMAGIA: "<<personajeParty[personajePosicion[i]].getMagia()<<" / "<<personajeParty[personajePosicion[i]].getMagiaMaxima()<<endl;
            }
            else {
                cout<<"\tMUERTO/A..."<<endl;
            }
        }

        cout<<endl<<personajeParty[personajePosicion[personajeAccion]].getNombre()<<" ("<<personajeParty[personajePosicion[personajeAccion]].getTipo()<<"):\n\n";
        
        cout<<"1. ATAQUE FISICO\n";
        cout<<"2. ATAQUE MAGICO (solo magos oscuros)\n";
        cout<<"3. CURAR ALIADO (solo magos blancos)\n";
        cout<<"4. DAR MAGIA A ALIADO (solo magos blancos)\n";
        cout<<"5. SALTEAR\n\n";
        cin>>opcion;

        switch (opcion) {
            case 1: personajeParty[personajePosicion[personajeAccion]].ataqueFisico(personajeEnemigo[seleccionarPersonaje(personajeEnemigo)]);
                    break;
                
            case 2: if (personajeParty[personajePosicion[personajeAccion]].getTipo() == "MAGO OSCURO") {
                        personajeParty[personajePosicion[personajeAccion]].ataqueMagico(personajeEnemigo[seleccionarPersonaje(personajeEnemigo)]);
                    }
                    else {
                        cout<<"ESTE PERSONAJE NO ES DEL TIPO REQUERIDO PARA REALIZAR ESTA ACCION\n\n";
                        system("PAUSE");
                    }
                    break;

            case 3: if (personajeParty[personajePosicion[personajeAccion]].getTipo() == "MAGO BLANCO") {
                        personajeParty[personajePosicion[personajeAccion]].curarAliado(personajeParty[seleccionarPersonaje(personajeParty, personajePosicion)]);
                    }
                    else {
                        cout<<"ESTE PERSONAJE NO ES DEL TIPO REQUERIDO PARA REALIZAR ESTA ACCION\n\n";
                        system("PAUSE");
                    }
                    break;

            case 4: if (personajeParty[personajePosicion[personajeAccion]].getTipo() == "MAGO BLANCO") {
                        personajeParty[personajePosicion[personajeAccion]].darMagiaAliado(personajeParty[seleccionarPersonaje(personajeParty, personajePosicion)]);
                    }
                    else {
                        cout<<"ESTE PERSONAJE NO ES DEL TIPO REQUERIDO PARA REALIZAR ESTA ACCION\n\n";
                        system("PAUSE");
                    }
                    break;

            case 5: break;
                        
            default: cout<<"LA OPCION INTRODUCIDA NO ES VALIDA\n\n";
                     system("PAUSE");
                     break;
        }
    }

    int seleccionarPersonaje (PersonajeEnemigo personajeEnemigo[3]) {
        int posicionObjetivo;
        
        system("clear");
        cout<<"OBJETIVO:\n\n";

        for (int i=0; i<3; i++)
            if (personajeEnemigo[i].getVida() > 0)
                cout<<i+1<<". "<<personajeEnemigo[i].getNombre()<<endl;

        cout<<"OBJETIVO: ";
        cin>>posicionObjetivo;

        return posicionObjetivo-1; //retorna la posicion dentro del array donde se encuentra el personaje objetivo
    }

    int seleccionarPersonaje (PersonajeParty personajeParty[5], int personajePosicion[3]) {
        int posicionObjetivo;

        do {
            system("clear");
            cout<<"OBJETIVO:\n\n";

            for (int i=0; i<3; i++)
                if (personajeParty[personajePosicion[i]].getVida() > 0)
                    cout<<i+1<<". "<<personajeParty[personajePosicion[i]].getNombre()<<endl;
        
            cout<<"OBJETIVO: ";
            cin>>posicionObjetivo;

            if (posicionObjetivo < 1 || posicionObjetivo > 3) {
                system("clear");
                cout<<"LA OPCION INTRODUCIDA ES INVALIDA\n\n";
                system("PAUSE");
            }

        } while (posicionObjetivo < 1 || posicionObjetivo > 3);

        return personajePosicion[posicionObjetivo-1]; //retorna la posicion dentro del array donde se encuentra el personaje objetivo   
    }

    bool verificarVida (PersonajeParty personajeParty[5], int personajePosicion[3]) { //Esta funcion sirve para verificar si siguen vivos todos los personajes de un determinado bando, de no ser asi se retornara false y acabara el combate
        int cont = 0;
        
        for (int i=0; i<3; i++)
            if (personajeParty[personajePosicion[i]].getVida() <= 0)
                cont++;
        
        if (cont == 3)
            return false;
        else
            return true;
    }

    bool verificarVida (PersonajeEnemigo personajeEnemigo[3]) { //Esta funcion sirve para verificar si siguen vivos todos los personajes de un determinado bando, de no ser asi se retornara false y acabara el combate
        int cont = 0;
        
        for (int i=0; i<3; i++)
            if (personajeEnemigo[i].getVida() <= 0)
                cont++;
        
        if (cont == 3)
            return false;
        else
            return true;
    }
};

class Piso { //Los pisos son los niveles del juego
private:
    int nivel; //Los niveles son cinco
    char matriz[8][13]; //Este seria el piso y su representacion grafica y logica
    int posicionX, posicionY; //Estos dos atributos representan la posicion del jugador dentro del piso
    Pozo pozo[6];

public:
    Piso (int _nivel) {
        PantallaInicioPozo(_nivel);

        this->nivel = _nivel;
        this->posicionX = 6;
        this->posicionY = 6;

        //DECLARO MATRIZ
        for (int fila=0; fila<8; fila++) {
            for (int columna=0; columna<13; columna++) {
                if (fila == 0 || fila == 7 || columna == 0 || columna == 12)
                    if (fila == 7 && columna == 6)
                        this->matriz[fila][columna] = ' ';
                    else
                        this->matriz[fila][columna] = '-';
                else
                    this->matriz[fila][columna] = ' ';
            }
        }

        //GENERO LOS ELEMENTOS EN EL TERRENO
        
        switch (this->nivel) {
            case 1: this->generarNivel1();
                    break;

            case 2: this->generarNivel2();
                    break;
            
            case 3: this->generarNivel3();
                    break;

            case 4: this->generarNivel4();
                    break;

            case 5: this->generarNivel5();
                    break;
        }
    }

    void moverPersonaje (PersonajeParty personajeParty[5], Items &items) {
        int nivelActual = this->nivel; 
        
        while (true) {
            this->mostrarMatriz();
            this->detectarTecla(personajeParty ,items);
            this->detectarPosicion(personajeParty, items);
            
            if (nivelActual != this->nivel)
                break;

            system("clear");
        }
    }

    void mostrarMatriz () {
    for (int fila=0; fila<8; fila++) {
        for (int columna=0; columna<13; columna++) {
            if (fila == this->posicionX && columna == this->posicionY)
                cout<<'0'<<" ";
            else
                cout<<this->matriz[fila][columna]<<" ";
        }
        cout<<endl;
    }
}

    void detectarTecla (PersonajeParty personajeParty[5] ,Items &items) {
        char tecla = cin.get();
        tecla = tolower(tecla);

        if (tecla == 'w') { // arriba
            if (this->posicionX != 1)
                this->posicionX--;
        }
        else if (tecla == 's') { //abajo
            if (this->posicionX != 6)
                this->posicionX++;
        }
        else if (tecla == 'a') { // izquierda
            if (this->posicionY != 1)
                this->posicionY--;
        }
        else if (tecla == 'd') { // derecha
            if (this->posicionY != 11)
                this->posicionY++;
        }
        else if (tecla == 'e') {
            items.menuInventario(personajeParty);
        }
    }

    void detectarPosicion (PersonajeParty personajeParty[5], Items &items) { //Para detectar si el jugador esta sobre una X o no
        for (int i=0; i<8; i++) {
            if (this->posicionX == this->pozo[i].getPosicionX() && this->posicionY == this->pozo[i].getPosicionY() && this->pozo[i].getEstado() == true) {
                pozo[i].ejecutarPozo(personajeParty, items, this->nivel);
                if (this->pozo[i].getTipo() != "jefe_salida") {
                    this->pozo[i].setEstado(false);
                    this->matriz[this->pozo[i].getPosicionX()][this->pozo[i].getPosicionY()] = ' ';
                }
                break;
            }
        }
    }

    bool verificarPosicionPozo (int cont, int posicionX, int posicionY) { //Esta funcion sirve para verificar si ya hay un pozo existente en la posicion generada. Si ya hay un pozo se retorna false, si no hay se retorna true
        if (posicionX != 6 && posicionY != 6) {
            for (int i=0; i<cont; i++) {
                if (this->pozo[i].getPosicionX() == posicionX && this->pozo[i].getPosicionY() == posicionY)
                    return false;
            } 
        }
        else {
            return false;
        }

        return true;
    }

    void PantallaInicioPozo (int piso) { //Este metodo sirve para mostrar el piso en el que acaba de entrar el jugador
    system("clear");
    cout<<"=======================\n";
    cout<<"\tPISO: "<<piso<<endl;
    cout<<"=======================\n\n";
    system("PAUSE");
    system("clear");
    }

    //GENERAR NIVELES
    void generarNivel1 () {
        int auxColumna, auxFila, contPozosGenerados = 0;

        this->pozo[0].setTipo("enemigos"); //Defino el tipo de las X
        this->pozo[1].setTipo("items");
        this->pozo[2].setTipo("jefe_salida");

        for (int i=0; i<3; i++) { //Asigno aleatoriamente un lugar dentro del piso a cada X
            do { //Verifico si ya existe un pozo en la posicion a generar
                auxColumna = rand()%(11-1 + 1) + 1; 
                auxFila = rand()%(6-1 + 1) + 1;
            } while (verificarPosicionPozo(contPozosGenerados, auxColumna, auxFila) == false);

            this->matriz[auxFila][auxColumna] = 'x';
            this->pozo[i].setPosicionX(auxFila);
            this->pozo[i].setPosicionY(auxColumna);
            contPozosGenerados++;
        }
    }

    void generarNivel2 () {
        int auxColumna, auxFila, contPozosGenerados = 0;

        this->pozo[0].setTipo("enemigos"); //Defino el tipo de las X
        this->pozo[1].setTipo("items");
        this->pozo[2].setTipo("jefe_salida");
        this->pozo[3].setTipo("personaje_party");

        for (int i=0; i<4; i++) { //Asigno aleatoriamente un lugar dentro del piso a cada X
            do { //Verifico si ya existe un pozo en la posicion a generar
                auxColumna = rand()%(11-1 + 1) + 1; 
                auxFila = rand()%(6-1 + 1) + 1;
            } while (verificarPosicionPozo(contPozosGenerados, auxColumna, auxFila) == false);
            this->matriz[auxFila][auxColumna] = 'x';
            this->pozo[i].setPosicionX(auxFila);
            this->pozo[i].setPosicionY(auxColumna);
        }
    }

    void generarNivel3 () {
        int auxColumna, auxFila, contPozosGenerados = 0;

        this->pozo[0].setTipo("enemigos"); //Defino el tipo de las X
        this->pozo[1].setTipo("enemigos");
        this->pozo[2].setTipo("enemigos");
        this->pozo[3].setTipo("items");
        this->pozo[4].setTipo("jefe_salida");

        for (int i=0; i<5; i++) { //Asigno aleatoriamente un lugar dentro del piso a cada X
            do { //Verifico si ya existe un pozo en la posicion a generar
                auxColumna = rand()%(11-1 + 1) + 1; 
                auxFila = rand()%(6-1 + 1) + 1;
            } while (verificarPosicionPozo(contPozosGenerados, auxColumna, auxFila) == false);
            this->matriz[auxFila][auxColumna] = 'x';
            this->pozo[i].setPosicionX(auxFila);
            this->pozo[i].setPosicionY(auxColumna);
        }
    }

    void generarNivel4 () {
        int auxColumna, auxFila, contPozosGenerados = 0;

        this->pozo[0].setTipo("enemigos"); //Defino el tipo de las X
        this->pozo[1].setTipo("enemigos");
        this->pozo[2].setTipo("items");
        this->pozo[3].setTipo("items");
        this->pozo[4].setTipo("jefe_salida");
        this->pozo[5].setTipo("personaje_party");

        for (int i=0; i<6; i++) { //Asigno aleatoriamente un lugar dentro del piso a cada X
            do { //Verifico si ya existe un pozo en la posicion a generar
                auxColumna = rand()%(11-1 + 1) + 1; 
                auxFila = rand()%(6-1 + 1) + 1;
            } while (verificarPosicionPozo(contPozosGenerados, auxColumna, auxFila) == false);
            this->matriz[auxFila][auxColumna] = 'x';
            this->pozo[i].setPosicionX(auxFila);
            this->pozo[i].setPosicionY(auxColumna);
        }
    }

    void generarNivel5 () {
        this->pozo[0].setTipo("jefe_salida"); //Defino el tipo de la X

        this->matriz[2][6] = 'x'; //Asigno un lugar ya determinado dentro del piso para la X
        this->pozo[0].setPosicionX(2);
        this->pozo[0].setPosicionY(6);
    }
};

//Funciones
int main () {
    srand(time(NULL)); //Para poder utilizar aleatoridad en distintos metodos
    menuPrincipal();

    return 0;
}

void menuPrincipal () {
    int opcion;
    
    do {
        system("clear");
        cout<<"------------- MENU -------------\n";
        cout<<"1. Comenzar juego\n";
        cout<<"2. Instrucciones\n";
        cout<<"3. Salir\n\n";
        cin>>opcion;
        system("clear");

        switch (opcion) {
            case 1: opcion_1();
                    break;

            case 2: opcion_2();
                    break;

            case 3: cout<<"SALIENDO...\n\n";
                    system("PAUSE");
                    break;
            
            default: cout<<"Opcion no valida\n\n";
                     system("PAUSE");
                     break;

        }

    } while (opcion != 3);
}

//OPCIONES 
void opcion_1 () {
    PersonajeParty personajeParty[5];
    for (int i=0; i<3; i++)
        personajeParty[i].setPuesto(i+1);

    Items items = Items();

    personajeParty[0].crearPersonaje("TIDUS", "CABALLERO", 100, 0, 1000, 500);
    personajeParty[1].crearPersonaje("CLOUD", "CABALLERO", 90, 0, 1000, 500);
    personajeParty[2].crearPersonaje("HERMIONE", "MAGO OSCURO", 15, 95, 750, 1000);

    //PISO 1 
    //En este piso vera un pozo con items, un grupo de enemigos y el combate contra el jefe (tres pozos).
    Piso piso_1 = Piso(1);
    piso_1.moverPersonaje(personajeParty, items);

    //PISO 2
    //En este piso vera un pozo con un mago blanco, un combate de con un grupo de enemigos, un pozo con items ademas del jefe (cuatro pozos).
    Piso piso_2 = Piso(2);
    piso_2.moverPersonaje(personajeParty, items);

    //PISO 3
    //En este piso veran tres combates con enemigos, un item y el combate contra el jefe (cinco pozos).
    Piso piso_3 = Piso(3);
    piso_3.moverPersonaje(personajeParty, items);

    //PISO 4
    //En este piso vera un personaje de tipo caballero muy fuerte, dos pozos con items, dos combates con grupos de enemigos ademas del jefe (seis pozos).
    Piso piso_4 = Piso(4);
    piso_4.moverPersonaje(personajeParty, items);

    //PISO 5
    //En este piso solo estara el combate contra el jefe final (un pozo).
    Piso piso_5 = Piso(5);
    piso_5.moverPersonaje(personajeParty, items);

    //MENSAJE DE VICTORIA
    system("clear");
    cout<<"======================================\n";
    //En este piso solo estara el combate contra el jefe final (un pozo).
    cout<<"\tGANASTE, FIN DEL JUEGO\n";
    cout<<"======================================\n\n";
    system("PAUSE");
}

void opcion_2 () {
    system("clear");

    fstream archivo;
    string str;
    
    archivo.open("instrucciones.txt", ios::in);
    while (getline(archivo, str)) {
        cout<<str<<endl;
    }
    archivo.close();
    
    system("PAUSE");
}