#include <sstream>
#include <vector>
#include <iostream>
#include <climits>

inline static div_t my_div(int numero, int denominador){
        div_t resultado;
        resultado.quot = numero / denominador;
        resultado.rem = numero - denominador * resultado.quot;
        return resultado;
}

inline static ldiv_t my_ldiv(long numero, long denominador){
        ldiv_t resultado;
        resultado.quot = numero / denominador;
        resultado.rem = numero - denominador * resultado.quot;
        return resultado;
}

inline static lldiv_t my_lldiv(long long numero, long long denominador){
        lldiv_t resultado;
        resultado.quot = numero / denominador;
        resultado.rem = numero - denominador * resultado.quot;
        return resultado;
}
