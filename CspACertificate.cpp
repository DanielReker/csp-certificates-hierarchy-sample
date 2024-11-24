#include "CspACertificate.h"
#include "CspA.h"

CspACertificate::CspACertificate(CspA& csp, std::string name, const std::string& someCustomCspACertData)
    : owningCsp(csp), ownerName(std::move(name)), someCustomCspACertData(someCustomCspACertData) {
}

Blob CspACertificate::Encrypt(const Blob& data) {
    return owningCsp.EncryptWithCertificate(data, *this);
}

Blob CspACertificate::Sign(const Blob& data) {
    return owningCsp.SignWithCertificate(data, *this);
}

std::string CspACertificate::GetOwnerName() const {
    return ownerName;
}
