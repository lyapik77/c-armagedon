    #include <iostream>
#include <typeinfo>
#include "Pharmacy.h"
#include "Boutique.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Shop* shops[3];

    shops[0] = new Pharmacy("Здоровая семья", "ул. Ленина, 1", 2010, 101,
                            500000.0, 1000000.0, "9:00-21:00", 150, false);

    shops[1] = new Pharmacy("Доктор Пилюлькин", "ул. Гагарина, 5", 2015, 102,
                            300000.0, 600000.0, "8:00-22:00", 80, false);

    shops[2] = new Boutique("Люкс", "пр. Независимости, 10", 2018, 201,
                            800000.0, 1500000.0, "10:00-20:00", 30, false);

    std::cout << "=== Демонстрация полиморфизма (уплата налогов) ===\n";
    for (int i = 0; i < 3; ++i) {
        shops[i]->payTax();
    }

    std::cout << "\n=== Демонстрация(определение типа) ===\n";
    for (int i = 0; i < 3; ++i) {
        const std::type_info& typeInfo = typeid(*shops[i]);
        std::cout << "Объект " << i+1 << ": " << typeInfo.name()
                  << " (название: " << shops[i]->getName() << ")\n";

        if (dynamic_cast<Pharmacy*>(shops[i]))
            std::cout << "  -> Это аптека.\n";
        else if (dynamic_cast<Boutique*>(shops[i]))
            std::cout << "  -> Это бутик.\n";
    }

    // Итоговое состояние
    std::cout << "\n=== Итоговое состояние магазинов ===\n";
    for (int i = 0; i < 3; ++i) {
        shops[i]->printInfo();
        std::cout << "------------------------\n";
    }

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) {
        delete shops[i];
    }

    return 0;
}