#include "CspA.h"
#include "CspACertificate.h"
#include <iostream>

CspA::CspA() {
    certificates.push_back(std::make_shared<CspACertificate>(*this, "Alice", "Custom CSP A cert data 1"));
    certificates.push_back(std::make_shared<CspACertificate>(*this, "Bob", "Custom CSP A cert data 2"));
}

std::vector<std::shared_ptr<ICertificate>> CspA::GetCertificates() {
    return { certificates.begin(), certificates.end() };
}

Blob CspA::EncryptWithCertificate(const Blob& data, const CspACertificate& cert) {
    std::cout << "Encrypted with CSP A, certificate: " << cert.GetOwnerName() << std::endl;
    std::cout << "Custom data: " << cert.someCustomCspACertData << std::endl;
    return {};
}

Blob CspA::SignWithCertificate(const Blob& data, const CspACertificate& cert) {
    std::cout << "Signed with CSP A, certificate: " << cert.someCustomCspACertData << std::endl;
    std::cout << "Custom data: " << cert.someCustomCspACertData << std::endl;
    return {};
}
