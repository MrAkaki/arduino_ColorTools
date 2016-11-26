# AVB Color tools
Libreria para trabajar con animacion de colores de forma sensilla.

## Para que?
 Cuando ocupas hacer cambios de color de forma mas sencilla usar el modelo de color HSV(https://en.wikipedia.org/wiki/HSL_and_HSV) es mas conveniente(desde mi perspectiva)  Y por que convertir a RGB, normalmente los pixeles, las tiras de leds, las matrices y las pantallas se basan el en modelo RGB.

## Codigo
### Estructuras de datos

```code
    class HSV {
      public:
        // Hue, tono
        float h;
        // Saturation, saturacion
        float s;
        // Value, valor
        float v;

        //Constructor por defecto
        HSV();

        //Constructor con parametros
        HSV(float h,float s, float v);

        //Contructor de copia
        HSV(const HSV &otro);

        //Sobrecarga de operador =
        HSV operator=(const HSV &otro);

    };

    class RGB {
      public:
        // variable para red, rojo
        uint8_t r;
        // variable para green, verde
        uint8_t g;
        // varialbe para blue, azul
        uint8_t b;

        //Contructor por defecto
        RGB();

        //Contructor con parametros
        RGB(uint8_t r,uint8_t g, uint8_t b);

        //Contructor de copia
        RGB(const RGB &otro);

        //Sobrecarga de operador =
        RGB& operator=(const RGB &otro);

    };

```
### Funciones
```code
    /**
    * Transforma del modelo de color HSV al modelo de color RGB.
    * @param HSV &input, entrada HSV a tranformar.
    * @param RGB *responce, salida RGB tranformado.
    **/
    void HSV2RGB(HSV &input, RGB *responce);

    /**
    * Transforma del modelo de color RGB al modelo de color HSV.
    * @param RGB &input, entrada RGB a tranformar.
    * @param HSV *responce, salida HSV tranformado.
    **/
    void RGB2HSV(RGB input, HSV *responce);
```


<br/><br/>
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">AVB Color Tools</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/alexvargasbenamburg/ColorTools" property="cc:attributionName" rel="cc:attributionURL">Alex Vargas Benamburg</a> <br/>is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
