#include <iostream>
#include <string>

using namespace std;

int main() {
    int Opcion = 0;
    int contadorOperario = 0;
    int contadorTecnico = 0;
    int contadorProfesional = 0;
    double salarioOperario = 0;
    double salarioTecnico = 0;
    double salarioProfesional = 0;
    char TipoDeEmpleado;
    double Aumento;
    double SalarioBase;
    double SalarioBruto;
    double SalarioNeto;
    float HorasLaboradas;
    double Deducciones;
    double PrecioPorHora;
    bool MasRegistros = true;
    string Cedula;
    string Nombre;
    int n = 20;
    string Cedulas[n];
    string Nombres[n];
    char TipoDeEmpleados[n];
    double HorasTrabajadas[n];
    double PreciosPorHoras[n];
    double SalariosNetos[n];
    int Estado;
    int EmpleadoIndex = 0;

    while (MasRegistros) {
        cout << "Que deseas hacer?\n"
             << "1. Ingresar un Empleado\n"
             << "2. Consultar un Empleado\n"
             << "3. Modificar un Empleado\n"
             << "4. Borrar un Empleado\n";
        cin >> Opcion;

        switch (Opcion) {
            case 1:
                if (EmpleadoIndex >= n) {
                    cout << "No se pueden ingresar mas empleados. Capacidad maxima alcanzada.\n";
                    break;
                }
                cout << "Digite numero de cedula: ";
                cin >> Cedula;
                cout << "Ingrese su nombre: ";
                cin >> Nombre;
                while (true) {
                    cout << "Ingrese el tipo de empleado\n"
                         << "1-Operario 2-Tecnico 3-Profesional: ";
                    cin >> TipoDeEmpleado;
                    if (TipoDeEmpleado == '1' || TipoDeEmpleado == '2' || TipoDeEmpleado == '3') break;
                    cout << "Tipo de Empleado invalido (1-2-3)\n" << endl;
                }
                while (true) {
                    cout << "Digite numero de horas laboradas: ";
                    Estado = scanf("%f", &HorasLaboradas);
                    getchar();
                    if (HorasLaboradas > 0 && HorasLaboradas <= 192 && Estado == 1) break;
                    cout << "Horas no validas (Horas Laborales maximas al mes 192)\n" << endl;
                }
                while (true) {
                    cout << "Digite el precio por hora: ";
                    Estado = scanf("%lf", &PrecioPorHora);
                    getchar();
                    if (PrecioPorHora >= 1494.20 && Estado == 1) break;
                    cout << "Precio no valido (El salario minimo por hora es de 1494.20 colones)\n" << endl;
                }
                SalarioBase = HorasLaboradas * PrecioPorHora;

                switch (TipoDeEmpleado) {
                    case '1': Aumento = SalarioBase * 0.15; break;
                    case '2': Aumento = SalarioBase * 0.10; break;
                    case '3': Aumento = SalarioBase * 0.05; break;
                }
                SalarioBruto = SalarioBase + Aumento;
                Deducciones = SalarioBruto * 0.0917;
                SalarioNeto = SalarioBruto - Deducciones;

                switch (TipoDeEmpleado) {
                    case '1':
                        contadorOperario++;
                        salarioOperario += SalarioNeto;
                        break;
                    case '2':
                        contadorTecnico++;
                        salarioTecnico += SalarioNeto;
                        break;
                    case '3':
                        contadorProfesional++;
                        salarioProfesional += SalarioNeto;
                        break;
                }

                Cedulas[EmpleadoIndex] = Cedula;
                Nombres[EmpleadoIndex] = Nombre;
                TipoDeEmpleados[EmpleadoIndex] = TipoDeEmpleado;
                HorasTrabajadas[EmpleadoIndex] = HorasLaboradas;
                PreciosPorHoras[EmpleadoIndex] = PrecioPorHora;
                SalariosNetos[EmpleadoIndex] = SalarioNeto;
                EmpleadoIndex++;

                cout << "\n\t >Información del empleado:\n";
                cout << "Cedula: " << Cedula << endl;
                cout << "Nombre: " << Nombre << endl;
                cout << "Tipo Empleado: " << TipoDeEmpleado << endl;
                cout << "Salario por Hora: " << PrecioPorHora << endl;
                cout << "Cantidad de Horas: " << HorasLaboradas << endl;
                cout << "Salario Ordinario: " << SalarioBase << endl;
                cout << "Aumento: " << Aumento << endl;
                cout << "Salario Bruto: " << SalarioBruto << endl;
                cout << "Deduccion CCSS: " << Deducciones << endl;
                cout << "Salario Neto: " << SalarioNeto << endl;
                break;

            case 2:
                cout << "Digite numero de cedula del empleado que desea consultar: ";
                cin >> Cedula;
                for (int i = 0; i < EmpleadoIndex; i++) {
                    if (Cedulas[i] == Cedula) {
                        cout << "\n\t >Información del empleado:\n";
                        cout << "Cedula: " << Cedulas[i] << endl;
                        cout << "Nombre: " << Nombres[i] << endl;
                        cout << "Tipo Empleado: " << TipoDeEmpleados[i] << endl;
                        cout << "Salario por Hora: " << PreciosPorHoras[i] << endl;
                        cout << "Cantidad de Horas: " << HorasTrabajadas[i] << endl;
                        cout << "Salario Neto: " << SalariosNetos[i] << endl;
                        break;
                    }
                }
                break;

            case 3:
                cout << "Digite numero de cedula del empleado que desea modificar: ";
                cin >> Cedula;
                for (int i = 0; i < EmpleadoIndex; i++) {
                    if (Cedulas[i] == Cedula) {
                        // Ajustar los contadores y acumulados antes de modificar
                        switch (TipoDeEmpleados[i]) {
                            case '1':
                                contadorOperario--;
                                salarioOperario -= SalariosNetos[i];
                                break;
                            case '2':
                                contadorTecnico--;
                                salarioTecnico -= SalariosNetos[i];
                                break;
                            case '3':
                                contadorProfesional--;
                                salarioProfesional -= SalariosNetos[i];
                                break;
                        }

                        cout << "Ingrese el nuevo nombre: ";
                        cin >> Nombres[i];
                        while (true) {
                            cout << "Ingrese el tipo de empleado\n"
                                 << "1-Operario 2-Tecnico 3-Profesional: ";
                            cin >> TipoDeEmpleados[i];
                            if (TipoDeEmpleados[i] == '1' || TipoDeEmpleados[i] == '2' || TipoDeEmpleados[i] == '3') break;
                            cout << "Tipo de Empleado inválido (1-2-3)\n" << endl;
                        }
                        while (true) {
                            cout << "Digite numero de horas laboradas: ";
                            Estado = scanf("%f", &HorasLaboradas);
                            getchar();
                            if (HorasLaboradas > 0 && HorasLaboradas <= 192 && Estado == 1) break;
                            cout << "Horas no válidas (Horas Laborales máximas al mes 192)\n" << endl;
                        }
                        while (true) {
                            cout << "Digite el precio por hora: ";
                            Estado = scanf("%lf", &PrecioPorHora);
                            getchar();
                            if (PrecioPorHora >= 1494.20 && Estado == 1) break;
                            cout << "Precio no válido (El salario mínimo por hora es de 1494.20 colones)\n" << endl;
                        }
                        SalarioBase = HorasLaboradas * PrecioPorHora;

                        switch (TipoDeEmpleados[i]) {
                            case '1': Aumento = SalarioBase * 0.15; break;
                            case '2': Aumento = SalarioBase * 0.10; break;
                            case '3': Aumento = SalarioBase * 0.05; break;
                        }

                        SalarioBruto = SalarioBase + Aumento;
                        Deducciones = SalarioBruto * 0.0917;
                        SalarioNeto = SalarioBruto - Deducciones;
                        SalariosNetos[i] = SalarioNeto;

                        // Ajustar los contadores y acumulados después de modificar
                        switch (TipoDeEmpleados[i]) {
                            case '1':
                                contadorOperario++;
                                salarioOperario += SalarioNeto;
                                break;
                            case '2':
                                contadorTecnico++;
                                salarioTecnico += SalarioNeto;
                                break;
                            case '3':
                                contadorProfesional++;
                                salarioProfesional += SalarioNeto;
                                break;
                        }

                        cout << "\n\t >Información del empleado modificada:\n";
                        cout << "Cedula: " << Cedulas[i] << endl;
                        cout << "Nombre: " << Nombres[i] << endl;
                        cout << "Tipo Empleado: " << TipoDeEmpleados[i] << endl;
                        cout << "Salario por Hora: " << PrecioPorHora << endl;
                        cout << "Cantidad de Horas: " << HorasLaboradas << endl;
                        cout << "Salario Neto: " << SalariosNetos[i] << endl;
                        break;
                    }
                }
                break;

            case 4:
                cout << "Digite numero de cedula del empleado que desea borrar: ";
                cin >> Cedula;
                for (int i = 0; i < EmpleadoIndex; i++) {
                    if (Cedulas[i] == Cedula) {
                        switch (TipoDeEmpleados[i]) {
                            case '1':
                                contadorOperario--;
                                salarioOperario -= SalariosNetos[i];
                                break;
                            case '2':
                                contadorTecnico--;
                                salarioTecnico -= SalariosNetos[i];
                                break;
                            case '3':
                                contadorProfesional--;
                                salarioProfesional -= SalariosNetos[i];
                                break;
                        }
                        // Eliminar al empleado moviendo los elementos en el arreglo
                        for (int j = i; j < EmpleadoIndex - 1; j++) {
                            Cedulas[j] = Cedulas[j + 1];
                            Nombres[j] = Nombres[j + 1];
                            TipoDeEmpleados[j] = TipoDeEmpleados[j + 1];
                            HorasTrabajadas[j] = HorasTrabajadas[j + 1];
                            PreciosPorHoras[j] = PreciosPorHoras[j + 1];
                            SalariosNetos[j] = SalariosNetos[j + 1];
                        }
                        EmpleadoIndex--;
                        cout << "Empleado borrado exitosamente.\n";
                        break;
                    }
                }
                break;
        }

        char Continuar;
        cout << "\nContinuar? (s/n): ";
        cin >> Continuar;
        if (Continuar != 's' && Continuar != 'S') {
            MasRegistros = false;
        }
    }

    double promedioOperario = contadorOperario > 0 ? salarioOperario / contadorOperario : 0;
    double promedioTecnico = contadorTecnico > 0 ? salarioTecnico / contadorTecnico : 0;
    double promedioProfesional = contadorProfesional > 0 ? salarioProfesional / contadorProfesional : 0;

    cout << "\nEstadisticas Finales:\n";
    cout << "Cantidad Empleados Tipo Operarios: " << contadorOperario << endl;
    cout << "Acumulado Salario Neto para Operarios: " << salarioOperario << endl;
    cout << "Promedio Salario Neto para Operarios: " << promedioOperario << endl;
    cout << "Cantidad Empleados Tipo Tecnicos: " << contadorTecnico << endl;
    cout << "Acumulado Salario Neto para Tecnicos: " << salarioTecnico << endl;
    cout << "Promedio Salario Neto para Tecnicos: " << promedioTecnico << endl;
    cout << "Cantidad Empleados Tipo Profesionales: " << contadorProfesional << endl;
    cout << "Acumulado Salario Neto para Profesionales: " << salarioProfesional << endl;
    cout << "Promedio Salario Neto para Profesionales: " << promedioProfesional << endl;

    return 0;
}

