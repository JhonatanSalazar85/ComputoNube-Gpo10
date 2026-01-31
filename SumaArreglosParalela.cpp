// SumaArreglosParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib> // Para números aleatorios (rand)
#include <ctime>   // Para cambiar la semilla aleatoria

// Tamaño del arreglo (1000 elementos como pide la guía)
#define N 1000
#define CHUNK 100 // Tamaño del bloque para cada hilo 

int main()
{
    // 1. Inicialización de datos
    std::cout << "Iniciando Suma de Arreglos en Paralelo...\n";

    // Usamos vectores estáticos para este ejemplo
    int A[N];
    int B[N];
    int R[N]; // Arreglo Resultado

    // Semilla para que los números cambien en cada ejecución
    srand(time(0));

    // Genera los arreglos A y B con números aleatorios (0 a 99)
    // Secuencial porque es preparación de datos
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    int hilos_usados = 0;

    // 2. PROCESO PARALELO 
    
#pragma omp parallel for shared(A, B, R) schedule(static, CHUNK)
    for (int i = 0; i < N; i++)
    {
        // Solo para verificar
        if (i == 0) {
            hilos_usados = omp_get_num_threads();
        }

        // La operación matemática
        R[i] = A[i] + B[i];

        
    }

    // 3. Verificación de Resultados
    std::cout << "Calculo terminado utilizando " << hilos_usados << " hilos de tu procesador.\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Imprimiendo los primeros 10 resultados para validacion:\n";
    std::cout << "   A  +    B  =    R\n";
    std::cout << "--------------------------------------------------\n";

    // Imprimimos solo los primeros 10 para comprobar que la matemática es correcta
    for (int i = 0; i < 10; i++)
    {
        std::cout << "  " << A[i] << "  +   " << B[i] << "  =   " << R[i] << std::endl;
    }

    std::cin.get(); // Pausa
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
