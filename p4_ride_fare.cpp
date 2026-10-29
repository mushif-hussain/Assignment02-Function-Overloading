#include <iostream>
#include <fstream>
using namespace std;

double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);

int main()
{
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;


    int rideCount;
    cout << "How many rides? ";
    cin >> rideCount;

    ofstream fileOut("rides.txt");
    double totalCollected = 0.0;

    for (int i = 1; i <= rideCount; i++) {
        char vehicleType;
        double distanceKm;
        int promo;

        cout << "Ride " << i << " vehicle (B/R/C), km, promo %: ";
        cin >> vehicleType >> distanceKm >> promo;

        double currentFare = 0.0;
        if (promo == 0) {
            currentFare = fare(distanceKm, vehicleType);
        }
        else {
            currentFare = fare(distanceKm, vehicleType, promo);
        }

        totalCollected += currentFare;
        fileOut << "Ride " << i << " (" << vehicleType << "), " << distanceKm << " km -> Rs. " << currentFare << endl;
    }

    fileOut << "Total collected: Rs. " << totalCollected << endl;
    fileOut.close();

    return 0;
}

// Version 1
double fare(double km, double ratePerKm) {
    return 100.0 + (km * ratePerKm);
}

// Version 2
double fare(double km, double ratePerKm, bool peakHour)
{
    double baseVal = fare(km, ratePerKm);
    if (peakHour) {
        return baseVal * 1.20;
    }
    return baseVal;
}

// Version 3
double fare(double km, char vehicle)
{
    double perKmRate = 0.0;
    if (vehicle == 'B' || vehicle == 'b') perKmRate = 25.0;
    else if (vehicle == 'R' || vehicle == 'r') perKmRate = 35.0;
    else if (vehicle == 'C' || vehicle == 'c') perKmRate = 50.0;
    else return 0.0;

    return fare(km, perKmRate);
}


double fare(double km, char vehicle, int promoPercent)
{
    double originalFare = fare(km, vehicle);
    double discount = originalFare * (promoPercent / 100.0);
    return originalFare - discount;
}