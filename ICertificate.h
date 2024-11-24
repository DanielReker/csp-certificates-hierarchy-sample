#ifndef ICERTIFICATE_H
#define ICERTIFICATE_H

#include <string>
#include "Blob.h"

class ICertificate {
public:
    virtual ~ICertificate() = default;
    virtual Blob Encrypt(const Blob& data) = 0;
    virtual Blob Sign(const Blob& data) = 0;
    virtual std::string GetOwnerName() const = 0;
};

#endif // ICERTIFICATE_H