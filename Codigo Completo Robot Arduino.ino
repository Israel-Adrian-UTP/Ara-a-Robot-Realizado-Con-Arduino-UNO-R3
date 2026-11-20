#include <Servo.h>
#include <SoftwareSerial.h>

//Pin Bluetooth
SoftwareSerial BT(0, 1);

//Pata delante izquierda
Servo coxal1; 
Servo femur1; 

//Pata delante derecha
Servo coxal2;
Servo femur2;

//Pata atras izquierda
Servo coxal3;
Servo femur3;

//Pata atras derecha
Servo coxal4;
Servo femur4;

//Pines HC-SR04
const int trigPin = 10;
const int echoPin = 11;

// Función sensor HC-SR04
long medirDistancia() {
  // Enviar pulso
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Leer pulso
  long duration = pulseIn(echoPin, HIGH);
  
  //Calculo de distancia
  long distance = duration * 0.034 / 2;
  
  return distance;
}

void setup() {
  //Pin Pata 1
  coxal1.attach(2);
  femur1.attach(3);

  //Pin Pata 2
  coxal2.attach(4);
  femur2.attach(5);
  
  //Pin Pata 3
  coxal3.attach(6);
  femur3.attach(7);
  
  //Pin Pata 4
  coxal4.attach(8);
  femur4.attach(9);

  //Configurar Sensor Ultrasonico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Señal Bluetooth
  BT.begin(9600);
  
  //Serial Bluetooth
  Serial.begin(9600);
  
  //Posicion Inicial Pata 1
  coxal1.write(0);
  femur1.write(30);
  
  //Posicion Inicial Pata 2
  coxal2.write(180);
  femur2.write(30);
  
  //Posicion Inicial Pata 3
  coxal3.write(180);
  femur3.write(90);
  
  //Posicion Inicial Pata 4
  coxal4.write(0);
  femur4.write(0);
}

void loop() {
  //Bucle Comandos
  if (BT.available()) {
    //Salto De Linea
    String command = BT.readStringUntil('\n');
    //Recibir Comandos
    command.trim();
    
    //Bucle Opciones
    int cmd = 0;
    if (command == "p1") {
      cmd = 1;
      //Mover Pata 1
    } else if (command == "p2") {
      cmd = 2;
      //Mover Pata 2
    } else if (command == "p3") {
      cmd = 3;
      //Mover Pata 3
    } else if (command == "p4") {
      cmd = 4;
      //Mover Pata 4
    } else if (command == "s1") {
      cmd = 5;
      //Avanzar
    } else if (command == "s2") {
      cmd = 6;
      //Retroceder
    } else if (command == "s3") {
      cmd = 7;
      //Girar
    } else if (command == "a1") {
      cmd = 8;
      //Posicion 1 Movimiento 2 avanzar
    } else if (command == "a2") {
      cmd = 9;    
      //Posicion 2 Movimiento a posicion inicial
    } else if (command == "a3") {
      cmd = 10;
      //Posicion 3 Movimiento a posicion X
    } else if (command == "a4") {
      cmd = 11;
      //Posicion 4 Movimiento Baile
    } else {
      cmd = 12; //No Existe
    }

    switch (cmd) {
      //Mover Pata 1
      case 1:
        for (int angulo = 0; angulo <= 90; angulo++) {
          coxal1.write(angulo);
          delay(10);
        }
        for (int angulo = 30; angulo <= 90; angulo++) {
          femur1.write(angulo);
          delay(10);
        }
        for (int angulo = 0; angulo <= 90; angulo++) {
          coxal1.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 30; angulo--) {
          femur1.write(angulo);
          delay(10);
        } 
        break;
      //Mover Pata 2
      case 2:
        for (int angulo = 180; angulo >= 90; angulo--) {
          coxal2.write(angulo);
          delay(10);
        } 
        for (int angulo = 30; angulo >= 0; angulo--) {
          femur2.write(angulo);
          delay(10);
        } 
        for (int angulo = 90; angulo <= 180; angulo++) {
          coxal2.write(angulo);
          delay(10);
        }
        for (int angulo = 0; angulo <= 30; angulo++) {
          femur2.write(angulo);
          delay(10);
        }
        break;
      //Mover Pata 3
      case 3:
        for (int angulo = 180; angulo >= 90; angulo--) {
          coxal3.write(angulo);
          delay(10);
        } 
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur3.write(angulo);
          delay(10);
        } 
        for (int angulo = 90; angulo <= 180; angulo++) {
          coxal3.write(angulo);
          delay(10);
        }
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur3.write(angulo);
          delay(10);
        }
        break;
      //Mover Pata 4
      case 4:
        for (int angulo = 0; angulo <= 90; angulo++) {
          coxal4.write(angulo);
          delay(10);
        } 
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur4.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 0; angulo--) {
          coxal4.write(angulo);
          delay(10);
        } 
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur4.write(angulo);
          delay(10);
        } 
        break;
      //Avanzar
      case 5:
        // Medir la distancia
        long distancia = medirDistancia();
        
      if (distancia > 15) {

        for (int angulo = 90; angulo >= 0; angulo--) {
          femur3.write(angulo);
          delay(10);
        } 
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur4.write(angulo);
          delay(10);
        }

        for (int angulo = 30; angulo >= 0; angulo--) {
          femur1.write(angulo);
          delay(10);
        } 
        for (int angulo = 30; angulo <= 90; angulo++) {
          femur2.write(angulo);
          delay(10);
        }

        for (int angulo = 0; angulo <= 90; angulo++) {
          femur3.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur4.write(angulo);
          delay(10);
        } 

        for (int angulo = 0; angulo <= 30; angulo++) {
          femur1.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 30; angulo--) {
          femur2.write(angulo);
          delay(10);
        } 

      } else {
        //nada
      }

        break;
      //Retroceder
      case 6:
        for (int angulo = 30; angulo >= 0; angulo--) {
          femur1.write(angulo);
          delay(10);
        } 
        for (int angulo = 30; angulo <= 90; angulo++) {
          femur2.write(angulo);
          delay(10);
        }

        for (int angulo = 90; angulo >= 0; angulo--) {
          femur3.write(angulo);
          delay(10);
        } 
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur4.write(angulo);
          delay(10);
        }

        for (int angulo = 0; angulo <= 30; angulo++) {
          femur1.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 30; angulo--) {
          femur2.write(angulo);
          delay(10);
        } 

        for (int angulo = 0; angulo <= 90; angulo++) {
          femur3.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur4.write(angulo);
          delay(10);
        }
        break;
      //Girar
      case 7:
        for (int angulo = 0; angulo <= 90; angulo++) {
          coxal1.write(angulo);
          coxal3.write(180 - angulo);
          coxal2.write(180 - angulo);
          coxal4.write(angulo);
          delay(10);
        }

        for (int angulo = 90; angulo >= 0; angulo--) {
          coxal1.write(angulo);
          coxal3.write(180 - angulo);
          coxal2.write(180 - angulo);
          coxal4.write(angulo);
          delay(10);
        }
        break;      
      //Posicion 1 Movimiento 2 Avanzar
      case 8:
        //Levantar pata delantera izquierda y trasera derecha
        for (int angulo = 30; angulo >= 0; angulo--) {
          femur1.write(angulo);
          delay(10);
        }
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur4.write(angulo);
          delay(10);
        }
  
        //Rotar coxales
        for (int angulo = 0; angulo <= 90; angulo++) {
          coxal1.write(angulo);
          coxal4.write(angulo);
          delay(10);
        }
  
        //Bajar patas
        for (int angulo = 0; angulo <= 30; angulo++) {
          femur1.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur4.write(angulo);
          delay(10);
        }
  
        //Levantar pata delantera derecha y trasera izquierda
        for (int angulo = 30; angulo <= 90; angulo++) {
          femur2.write(angulo);
          delay(10);
        }
        for (int angulo = 90; angulo >= 0; angulo--) {
          femur3.write(angulo);
          delay(10);
        }
  
        //Rotar coxales
        for (int angulo = 180; angulo >= 90; angulo--) {
          coxal2.write(angulo);
          coxal3.write(angulo);
          delay(10);
        }
  
        //Bajar patas
        for (int angulo = 90; angulo >= 30; angulo--) {
          femur2.write(angulo);
          delay(10);
        }
        for (int angulo = 0; angulo <= 90; angulo++) {
          femur3.write(angulo);
          delay(10);
        }
        break;  
      //Posicion 2 Movimiento Posicion Inicial
      case 9:
      for (int angulo = 0; angulo <= 30; angulo++) {
        femur1.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 30; angulo++) {
        femur2.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 90; angulo++) {
        femur3.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 0; angulo++) {
        femur4.write(angulo);
        delay(10);
      }

      for (int angulo = 0; angulo <= 0; angulo++) {
        coxal1.write(angulo);
        delay(10);
      }
      for (int angulo = 180; angulo <= 180; angulo++) {
        coxal2.write(angulo);
        delay(10);
      }
      for (int angulo = 180; angulo <= 180; angulo++) {
        coxal3.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 0; angulo++) {
        coxal4.write(angulo);
        delay(10);
      }
        break;          
      //Posicion 3 Movimiento Posicion X
      case 10:
      for (int angulo = 0; angulo <= 30; angulo++) {
        femur1.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 30; angulo++) {
        femur2.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 90; angulo++) {
        femur3.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 0; angulo++) {
        femur4.write(angulo);
        delay(10);
      }

      for (int angulo = 0; angulo <= 45; angulo++) {
        coxal1.write(angulo);
        delay(10);
      }
      for (int angulo = 180; angulo >= 135; angulo--) {
        coxal2.write(angulo);
        delay(10);
      }
      for (int angulo = 180; angulo >= 135; angulo--) {
        coxal3.write(angulo);
        delay(10);
      }
      for (int angulo = 0; angulo <= 45; angulo++) {
        coxal4.write(angulo);
        delay(10);
      }
        break;  
      //Posicion 4 Baile
      case 11:
      for (int angulo = 0; angulo <= 30; angulo++) {
        femur1.write(angulo);
        femur4.write(angulo);
        delay(10);
      }
      for (int angulo = 90; angulo >= 30; angulo--) {
        femur2.write(angulo);
        femur3.write(angulo);
        delay(10);
      } 
      for (int angulo = 30; angulo >= 0; angulo--) {
        femur1.write(angulo);
        femur4.write(angulo);
        delay(10);
      } 
      for (int angulo = 30; angulo <= 90; angulo++) {
        femur2.write(angulo);
        femur3.write(angulo);
        delay(10);
      }      
        break;                

      default:  //No Encontrado
        BT.println("Comando Incorrecto");
        break;
    }
  
  
  }
}
