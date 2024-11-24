#ifndef ICSP_H
#define ICSP_H

#include <vector>
#include <memory>

class ICertificate;

class ICsp {
public:
    virtual ~ICsp() = default;
    virtual std::vector<std::shared_ptr<ICertificate>> GetCertificates() = 0;
};

#endif // ICSP_H