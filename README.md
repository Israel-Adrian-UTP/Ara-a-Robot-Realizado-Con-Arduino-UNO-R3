# Araña Robótica con Arduino UNO R3 — Optimización Energética (FEM)

Proyecto académico del curso de **FEM** en la **Universidad Tecnológica del Perú (UTP)** enfocado en el diseño, construcción y optimización energética de una araña robótica cuadrúpeda controlada por **Arduino UNO R3** con actuadores electromagnéticos (**MG90S**), detección de obstáculos (**HC-SR04**) y control remoto vía Bluetooth (**HC-05**).

---

## Autores

- **Israel Palomares D.** — Estudiante de 4.º ciclo de Ingeniería de Sistemas, UTP
- **Jordan Gutierrez U.** — Estudiante de 4.º ciclo de Ingeniería de Sistemas, UTP
- **Octavio Rodriguez C.** — Estudiante de 4.º ciclo de Ingeniería de Sistemas, UTP
- **Wilber Lozada H.** — Estudiante de 4.º ciclo de Ingeniería Industrial, UTP
- **Felix Yanac R.** — Estudiante de 4.º ciclo de Ingeniería Industrial, UTP

---

## Objetivos del proyecto

- **Objetivo general:** Desarrollar un sistema de control energético aplicable para una araña robótica.
- **Objetivos específicos:**
  - Diseñar el esquema de control energético.
  - Optimizar el algoritmo del software.
  - Evaluar el rendimiento en pruebas de campo.

---

## Características del prototipo

- **Configuración mecánica:** Araña cuadrúpeda de **4 patas** con **2 grados de libertad (GDL)** por extremidad (unión de eslabones de fémur y coxal).
- **Dimensiones y peso:** ~**0,12 m** de altura y **0,45 kg** de peso final (tras pasar de una estructura metálica descartada de **1,5 kg** a piezas impresas en **PLA** mediante modelado 3D en **Tinkercad**).
- **Control y expansión:** **Arduino UNO R3** integrado con **Sensor Shield V5**.
- **Actuación:** **8 servomotores MG90S** de engranaje metálico (2 por pata).
- **Sensores y conectividad:** Sensor ultrasónico **HC-SR04** para detección de obstáculos y módulo Bluetooth **HC-05** para control remoto.
- **Alimentación:** Configuración con baterías de **1,5 V** (paquete de 4 baterías AA / 2A conectado a la etapa de potencia).

---

## Fundamentos físicos y experimentación

El análisis del proyecto relaciona los principios electromagnéticos y eléctricos con las mediciones experimentales del servomotor **MG90S**:

- **Ley de Lorentz:** $F = q(E + v \times B)$ — describe la fuerza sobre cargas en movimiento dentro del campo magnético del actuador.
- **Fuerza sobre conductor con corriente y torque:** $F = I \cdot L \cdot B$. Con $L = 0,08\text{ m}$, $B = 0,25\text{ T}$ e $I = 0,52\text{ A}$, se obtiene $F = 10,4 \times 10^{-3}\text{ N}$, asociada a un torque medido de **1,8 kg·cm**.
- **Ley de Ampère:** $\oint B \cdot dl = \mu_0 I_{\text{enc}}$ y $B = \frac{\mu_0 \cdot N \cdot I}{L}$. Para $N = 150$ vueltas, $L = 0,02$ e $I = 0,38\text{ A}$, resulta $B \approx 3,58 \times 10^{-3}\text{ T}$.
- **Ley de Ohm y optimización de voltaje:** $V = I \cdot R$. Con resistencia medida $R = 5,2\ \Omega$, $I_{\text{reposo}} = 0,12\text{ A}$ e $I_{\text{movimiento}} = 0,38\text{ A}$, el ajuste de alimentación de **6 V a 5 V** redujo el consumo en un **18 %** sin afectar el rendimiento.
- **Potencia eléctrica ($P = V \cdot I$) a 5,0 V:**

| Modo Operativo | Corriente ($I$) | Voltaje ($V$) | Potencia ($P$) |
| :--- | :---: | :---: | :---: |
| Reposo | 0,01 A | 5,00 V | 0,05 W |
| Caminata | 0,02 A | 5,00 V | 0,10 W |
| Giro | 0,02 A | 5,00 V | 0,10 W |
| Máxima Carga | 1,20 A | 5,00 V | 6,00 W |

- **Modelo de descarga de voltaje por minuto:** $V(t) = 6 - 0,08t$.

---

## Aplicaciones y proyección

- **Actual:** Optimización energética en robótica biomimética de bajo costo.
- **A futuro:** Monitoreo y exploración de espacios confinados, así como localización de víctimas en estructuras colapsadas.

---

## Repositorio y documentación

- **Repositorio:** [Israel-Adrian-UTP/Ara-a-Robot-Realizado-Con-Arduino-UNO-R3](https://github.com/Israel-Adrian-UTP/Ara-a-Robot-Realizado-Con-Arduino-UNO-R3)
- **Documento de referencia:** *Informe final del proyecto de curso de FEM — Optimización energética de una araña robótica controlada por Arduino con actuadores electromagnéticos para aplicaciones en ingeniería* (UTP).