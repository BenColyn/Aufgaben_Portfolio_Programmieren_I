int main() {
    std::shared_ptr<car::BaseCar> myCar;
    int choice;

    std::cout << "Wähle ein Auto: (1) Sportwagen, (2) LKW: ";
    std::cin >> choice;

    if (choice == 1) {
        myCar = std::make_shared<car::RaceCar>();
    } // ... weitere Auswahl

    if (myCar) {
        myCar->startEngine();
        myCar->accelerate();
        myCar->turnLeft();
        myCar->brake();
    }

    return 0;
}