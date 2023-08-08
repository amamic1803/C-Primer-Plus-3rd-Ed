#include <stdio.h>


void ch03_ex06(void) {
    double const water_mol_mass = 3.0e-23;
    int const quart_in_grams = 950;
    int water_amount;
    double water_molecules;

    printf("Enter amount of water (in quarts):\n");
    scanf("%d", &water_amount);
    water_molecules = (water_amount * quart_in_grams) / water_mol_mass;
    printf("There are about %.0f water molecules in %d quarts of water.", water_molecules, water_amount);
}