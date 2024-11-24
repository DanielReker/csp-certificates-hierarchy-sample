#ifndef CSPA_H
#define CSPA_H

#include <vector>
#include <memory>
#include "ICsp.h"
#include "Blob.h"

class CspACertificate;

class CspA : public ICsp {
public:
    CspA();

    std::vector<std::shared_ptr<ICertificate>> GetCertificates() override;
    Blob EncryptWithCertificate(const Blob& data, const CspACertificate& cert);
    Blob SignWithCertificate(const Blob& data, const CspACertificate& cert);

private:
    std::vector<std::shared_ptr<CspACertificate>> certificates;
};

#endif // CSPA_H
