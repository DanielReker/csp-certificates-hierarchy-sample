#include <iostream>
#include "CspA.h"
#include "ICsp.h"
#include "ICertificate.h"

int main() {
    srand(time(nullptr));

    // Create a CSP
    CspA cspA;
    ICsp* csp = &cspA;

    // Get certificates
    auto certificates = csp->GetCertificates();

    // Select a certificate
    auto cert = certificates[rand() % 2];
    std::cout << "Selected certificate owned by: " << cert->GetOwnerName() << std::endl;

    // Perform cryptographic operations
    Blob data = { std::byte(0x01), std::byte(0x02), std::byte(0x03) };
    cert->Encrypt(data);
    cert->Sign(data);

    return 0;
}
