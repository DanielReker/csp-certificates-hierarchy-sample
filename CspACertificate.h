#ifndef CSPA_CERTIFICATE_H
#define CSPA_CERTIFICATE_H

#include "ICertificate.h"
#include <string>

class CspA;

class CspACertificate : public ICertificate {
public:
    CspACertificate(CspA& csp, std::string name, const std::string& someCustomCspACertData);

    Blob Encrypt(const Blob& data) override;
    Blob Sign(const Blob& data) override;
    std::string GetOwnerName() const override;

    std::string someCustomCspACertData;

private:
    CspA& owningCsp;
    std::string ownerName;
};

#endif // CSPA_CERTIFICATE_H
