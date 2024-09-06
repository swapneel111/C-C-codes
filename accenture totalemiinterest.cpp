#include <stdio.h>
#include <math.h>

double calculateTotalInterest(double principal, int tenure, int numSlabs, double slabs[][2]) {
    double totalInterest = 0.0;
    double monthlyInterestRate;
    int monthsRemaining = tenure * 12;
    
    for (int i = 0; i < numSlabs; i++) {
        int slabYears = (int)slabs[i][0];
        double slabRate = slabs[i][1];
        int slabMonths = slabYears * 12;
        
        if (monthsRemaining <= 0) {
            break;
        }
        
        if (slabMonths > monthsRemaining) {
            slabMonths = monthsRemaining;
        }
        
        monthlyInterestRate = slabRate / 12 / 100;
        
        double EMI = principal * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -slabMonths));
        double totalPayment = EMI * slabMonths;
        double interestPaid = totalPayment - principal;
        
        totalInterest += interestPaid;
        
        principal = totalPayment; // Remaining principal to be paid for next slab
        monthsRemaining -= slabMonths;
    }
    
    return totalInterest;
}

int main() {
    double principal;
    int tenure, numSlabsA, numSlabsB;
    
    // Read input
    scanf("%lf", &principal);
    scanf("%d", &tenure);
    
    scanf("%d", &numSlabsA);
    double slabsA[numSlabsA][2];
    for (int i = 0; i < numSlabsA; i++) {
        scanf("%lf %lf", &slabsA[i][0], &slabsA[i][1]);
    }
    
    scanf("%d", &numSlabsB);
    double slabsB[numSlabsB][2];
    for (int i = 0; i < numSlabsB; i++) {
        scanf("%lf %lf", &slabsB[i][0], &slabsB[i][1]);
    }
    
    // Calculate total interest for both banks
    double totalInterestA = calculateTotalInterest(principal, tenure, numSlabsA, slabsA);
    double totalInterestB = calculateTotalInterest(principal, tenure, numSlabsB, slabsB);
    
    // Output the decision
    if (totalInterestA < totalInterestB) {
        printf("Bank A\n");
    } else {
        printf("Bank B\n");
    }
    
    return 0;
}

