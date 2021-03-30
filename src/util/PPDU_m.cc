//
// Generated file, do not edit! Created by nedtool 4.6 from util/PPDU.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PPDU_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(pdDataInd);

pdDataInd::pdDataInd(const char *name, int kind) : ::cPacket(name,kind)
{
    this->psduLength_var = 0;
    this->ppduLinkQuality_var = 0;
}

pdDataInd::pdDataInd(const pdDataInd& other) : ::cPacket(other)
{
    copy(other);
}

pdDataInd::~pdDataInd()
{
}

pdDataInd& pdDataInd::operator=(const pdDataInd& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void pdDataInd::copy(const pdDataInd& other)
{
    this->psduLength_var = other.psduLength_var;
    this->ppduLinkQuality_var = other.ppduLinkQuality_var;
}

void pdDataInd::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->psduLength_var);
    doPacking(b,this->ppduLinkQuality_var);
}

void pdDataInd::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->psduLength_var);
    doUnpacking(b,this->ppduLinkQuality_var);
}

unsigned char pdDataInd::getPsduLength() const
{
    return psduLength_var;
}

void pdDataInd::setPsduLength(unsigned char psduLength)
{
    this->psduLength_var = psduLength;
}

unsigned char pdDataInd::getPpduLinkQuality() const
{
    return ppduLinkQuality_var;
}

void pdDataInd::setPpduLinkQuality(unsigned char ppduLinkQuality)
{
    this->ppduLinkQuality_var = ppduLinkQuality;
}

class pdDataIndDescriptor : public cClassDescriptor
{
  public:
    pdDataIndDescriptor();
    virtual ~pdDataIndDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(pdDataIndDescriptor);

pdDataIndDescriptor::pdDataIndDescriptor() : cClassDescriptor("pdDataInd", "cPacket")
{
}

pdDataIndDescriptor::~pdDataIndDescriptor()
{
}

bool pdDataIndDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<pdDataInd *>(obj)!=NULL;
}

const char *pdDataIndDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int pdDataIndDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int pdDataIndDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *pdDataIndDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "psduLength",
        "ppduLinkQuality",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int pdDataIndDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "psduLength")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppduLinkQuality")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *pdDataIndDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *pdDataIndDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int pdDataIndDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    pdDataInd *pp = (pdDataInd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string pdDataIndDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    pdDataInd *pp = (pdDataInd *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPsduLength());
        case 1: return ulong2string(pp->getPpduLinkQuality());
        default: return "";
    }
}

bool pdDataIndDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    pdDataInd *pp = (pdDataInd *)object; (void)pp;
    switch (field) {
        case 0: pp->setPsduLength(string2ulong(value)); return true;
        case 1: pp->setPpduLinkQuality(string2ulong(value)); return true;
        default: return false;
    }
}

const char *pdDataIndDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *pdDataIndDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    pdDataInd *pp = (pdDataInd *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ppdu);

ppdu::ppdu(const char *name, int kind) : ::cPacket(name,kind)
{
    for (unsigned int i=0; i<4; i++)
        this->Preamble_var[i] = 0;
    this->SFD_var = 0;
    this->PHR_var = 0;
}

ppdu::ppdu(const ppdu& other) : ::cPacket(other)
{
    copy(other);
}

ppdu::~ppdu()
{
}

ppdu& ppdu::operator=(const ppdu& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ppdu::copy(const ppdu& other)
{
    for (unsigned int i=0; i<4; i++)
        this->Preamble_var[i] = other.Preamble_var[i];
    this->SFD_var = other.SFD_var;
    this->PHR_var = other.PHR_var;
}

void ppdu::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->Preamble_var,4);
    doPacking(b,this->SFD_var);
    doPacking(b,this->PHR_var);
}

void ppdu::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->Preamble_var,4);
    doUnpacking(b,this->SFD_var);
    doUnpacking(b,this->PHR_var);
}

unsigned int ppdu::getPreambleArraySize() const
{
    return 4;
}

unsigned char ppdu::getPreamble(unsigned int k) const
{
    if (k>=4) throw cRuntimeError("Array of size 4 indexed by %lu", (unsigned long)k);
    return Preamble_var[k];
}

void ppdu::setPreamble(unsigned int k, unsigned char Preamble)
{
    if (k>=4) throw cRuntimeError("Array of size 4 indexed by %lu", (unsigned long)k);
    this->Preamble_var[k] = Preamble;
}

unsigned char ppdu::getSFD() const
{
    return SFD_var;
}

void ppdu::setSFD(unsigned char SFD)
{
    this->SFD_var = SFD;
}

unsigned char ppdu::getPHR() const
{
    return PHR_var;
}

void ppdu::setPHR(unsigned char PHR)
{
    this->PHR_var = PHR;
}

class ppduDescriptor : public cClassDescriptor
{
  public:
    ppduDescriptor();
    virtual ~ppduDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ppduDescriptor);

ppduDescriptor::ppduDescriptor() : cClassDescriptor("ppdu", "cPacket")
{
}

ppduDescriptor::~ppduDescriptor()
{
}

bool ppduDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ppdu *>(obj)!=NULL;
}

const char *ppduDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ppduDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int ppduDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *ppduDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Preamble",
        "SFD",
        "PHR",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int ppduDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "Preamble")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SFD")==0) return base+1;
    if (fieldName[0]=='P' && strcmp(fieldName, "PHR")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ppduDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
        "unsigned char",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *ppduDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ppduDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ppdu *pp = (ppdu *)object; (void)pp;
    switch (field) {
        case 0: return 4;
        default: return 0;
    }
}

std::string ppduDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ppdu *pp = (ppdu *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPreamble(i));
        case 1: return ulong2string(pp->getSFD());
        case 2: return ulong2string(pp->getPHR());
        default: return "";
    }
}

bool ppduDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ppdu *pp = (ppdu *)object; (void)pp;
    switch (field) {
        case 0: pp->setPreamble(i,string2ulong(value)); return true;
        case 1: pp->setSFD(string2ulong(value)); return true;
        case 2: pp->setPHR(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ppduDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ppduDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ppdu *pp = (ppdu *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(edConf);

edConf::edConf(const char *name, int kind) : ::cPacket(name,kind)
{
    this->status_var = 0;
    this->EnergyLevel_var = 0;
}

edConf::edConf(const edConf& other) : ::cPacket(other)
{
    copy(other);
}

edConf::~edConf()
{
}

edConf& edConf::operator=(const edConf& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void edConf::copy(const edConf& other)
{
    this->status_var = other.status_var;
    this->EnergyLevel_var = other.EnergyLevel_var;
}

void edConf::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->EnergyLevel_var);
}

void edConf::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->EnergyLevel_var);
}

unsigned char edConf::getStatus() const
{
    return status_var;
}

void edConf::setStatus(unsigned char status)
{
    this->status_var = status;
}

unsigned char edConf::getEnergyLevel() const
{
    return EnergyLevel_var;
}

void edConf::setEnergyLevel(unsigned char EnergyLevel)
{
    this->EnergyLevel_var = EnergyLevel;
}

class edConfDescriptor : public cClassDescriptor
{
  public:
    edConfDescriptor();
    virtual ~edConfDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(edConfDescriptor);

edConfDescriptor::edConfDescriptor() : cClassDescriptor("edConf", "cPacket")
{
}

edConfDescriptor::~edConfDescriptor()
{
}

bool edConfDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<edConf *>(obj)!=NULL;
}

const char *edConfDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int edConfDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int edConfDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *edConfDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "status",
        "EnergyLevel",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int edConfDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "EnergyLevel")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *edConfDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *edConfDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "phyState";
            return NULL;
        default: return NULL;
    }
}

int edConfDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    edConf *pp = (edConf *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string edConfDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    edConf *pp = (edConf *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getStatus());
        case 1: return ulong2string(pp->getEnergyLevel());
        default: return "";
    }
}

bool edConfDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    edConf *pp = (edConf *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setEnergyLevel(string2ulong(value)); return true;
        default: return false;
    }
}

const char *edConfDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *edConfDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    edConf *pp = (edConf *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(GetRequest);

GetRequest::GetRequest(const char *name, int kind) : ::cMessage(name,kind)
{
    this->PIBattr_var = 0;
    this->PIBind_var = 0;
}

GetRequest::GetRequest(const GetRequest& other) : ::cMessage(other)
{
    copy(other);
}

GetRequest::~GetRequest()
{
}

GetRequest& GetRequest::operator=(const GetRequest& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void GetRequest::copy(const GetRequest& other)
{
    this->PIBattr_var = other.PIBattr_var;
    this->PIBind_var = other.PIBind_var;
}

void GetRequest::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->PIBattr_var);
    doPacking(b,this->PIBind_var);
}

void GetRequest::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->PIBattr_var);
    doUnpacking(b,this->PIBind_var);
}

unsigned short GetRequest::getPIBattr() const
{
    return PIBattr_var;
}

void GetRequest::setPIBattr(unsigned short PIBattr)
{
    this->PIBattr_var = PIBattr;
}

unsigned short GetRequest::getPIBind() const
{
    return PIBind_var;
}

void GetRequest::setPIBind(unsigned short PIBind)
{
    this->PIBind_var = PIBind;
}

class GetRequestDescriptor : public cClassDescriptor
{
  public:
    GetRequestDescriptor();
    virtual ~GetRequestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(GetRequestDescriptor);

GetRequestDescriptor::GetRequestDescriptor() : cClassDescriptor("GetRequest", "cMessage")
{
}

GetRequestDescriptor::~GetRequestDescriptor()
{
}

bool GetRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<GetRequest *>(obj)!=NULL;
}

const char *GetRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int GetRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int GetRequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *GetRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "PIBattr",
        "PIBind",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int GetRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PIBattr")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PIBind")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *GetRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *GetRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyPIB_Attributes";
            return NULL;
        default: return NULL;
    }
}

int GetRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    GetRequest *pp = (GetRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string GetRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    GetRequest *pp = (GetRequest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPIBattr());
        case 1: return ulong2string(pp->getPIBind());
        default: return "";
    }
}

bool GetRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    GetRequest *pp = (GetRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setPIBattr(string2ulong(value)); return true;
        case 1: pp->setPIBind(string2ulong(value)); return true;
        default: return false;
    }
}

const char *GetRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *GetRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    GetRequest *pp = (GetRequest *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(GetConfirm);

GetConfirm::GetConfirm(const char *name, int kind) : ::GetRequest(name,kind)
{
    this->status_var = 0;
    this->value_var = 0;
}

GetConfirm::GetConfirm(const GetConfirm& other) : ::GetRequest(other)
{
    copy(other);
}

GetConfirm::~GetConfirm()
{
}

GetConfirm& GetConfirm::operator=(const GetConfirm& other)
{
    if (this==&other) return *this;
    ::GetRequest::operator=(other);
    copy(other);
    return *this;
}

void GetConfirm::copy(const GetConfirm& other)
{
    this->status_var = other.status_var;
    this->value_var = other.value_var;
}

void GetConfirm::parsimPack(cCommBuffer *b)
{
    ::GetRequest::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->value_var);
}

void GetConfirm::parsimUnpack(cCommBuffer *b)
{
    ::GetRequest::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->value_var);
}

unsigned short GetConfirm::getStatus() const
{
    return status_var;
}

void GetConfirm::setStatus(unsigned short status)
{
    this->status_var = status;
}

double GetConfirm::getValue() const
{
    return value_var;
}

void GetConfirm::setValue(double value)
{
    this->value_var = value;
}

class GetConfirmDescriptor : public cClassDescriptor
{
  public:
    GetConfirmDescriptor();
    virtual ~GetConfirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(GetConfirmDescriptor);

GetConfirmDescriptor::GetConfirmDescriptor() : cClassDescriptor("GetConfirm", "GetRequest")
{
}

GetConfirmDescriptor::~GetConfirmDescriptor()
{
}

bool GetConfirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<GetConfirm *>(obj)!=NULL;
}

const char *GetConfirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int GetConfirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int GetConfirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *GetConfirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "status",
        "value",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int GetConfirmDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *GetConfirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *GetConfirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyPIB_Status";
            return NULL;
        default: return NULL;
    }
}

int GetConfirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    GetConfirm *pp = (GetConfirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string GetConfirmDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    GetConfirm *pp = (GetConfirm *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getStatus());
        case 1: return double2string(pp->getValue());
        default: return "";
    }
}

bool GetConfirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    GetConfirm *pp = (GetConfirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2ulong(value)); return true;
        case 1: pp->setValue(string2double(value)); return true;
        default: return false;
    }
}

const char *GetConfirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *GetConfirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    GetConfirm *pp = (GetConfirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SetRequest);

SetRequest::SetRequest(const char *name, int kind) : ::cMessage(name,kind)
{
    this->PIBattr_var = 0;
    this->PIBind_var = 0;
    this->value_var = 0;
}

SetRequest::SetRequest(const SetRequest& other) : ::cMessage(other)
{
    copy(other);
}

SetRequest::~SetRequest()
{
}

SetRequest& SetRequest::operator=(const SetRequest& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SetRequest::copy(const SetRequest& other)
{
    this->PIBattr_var = other.PIBattr_var;
    this->PIBind_var = other.PIBind_var;
    this->value_var = other.value_var;
}

void SetRequest::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->PIBattr_var);
    doPacking(b,this->PIBind_var);
    doPacking(b,this->value_var);
}

void SetRequest::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->PIBattr_var);
    doUnpacking(b,this->PIBind_var);
    doUnpacking(b,this->value_var);
}

unsigned short SetRequest::getPIBattr() const
{
    return PIBattr_var;
}

void SetRequest::setPIBattr(unsigned short PIBattr)
{
    this->PIBattr_var = PIBattr;
}

unsigned short SetRequest::getPIBind() const
{
    return PIBind_var;
}

void SetRequest::setPIBind(unsigned short PIBind)
{
    this->PIBind_var = PIBind;
}

double SetRequest::getValue() const
{
    return value_var;
}

void SetRequest::setValue(double value)
{
    this->value_var = value;
}

class SetRequestDescriptor : public cClassDescriptor
{
  public:
    SetRequestDescriptor();
    virtual ~SetRequestDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SetRequestDescriptor);

SetRequestDescriptor::SetRequestDescriptor() : cClassDescriptor("SetRequest", "cMessage")
{
}

SetRequestDescriptor::~SetRequestDescriptor()
{
}

bool SetRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SetRequest *>(obj)!=NULL;
}

const char *SetRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SetRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SetRequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SetRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "PIBattr",
        "PIBind",
        "value",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SetRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PIBattr")==0) return base+0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PIBind")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SetRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SetRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyPIB_Attributes";
            return NULL;
        default: return NULL;
    }
}

int SetRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SetRequest *pp = (SetRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SetRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SetRequest *pp = (SetRequest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPIBattr());
        case 1: return ulong2string(pp->getPIBind());
        case 2: return double2string(pp->getValue());
        default: return "";
    }
}

bool SetRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SetRequest *pp = (SetRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setPIBattr(string2ulong(value)); return true;
        case 1: pp->setPIBind(string2ulong(value)); return true;
        case 2: pp->setValue(string2double(value)); return true;
        default: return false;
    }
}

const char *SetRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *SetRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SetRequest *pp = (SetRequest *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SetConfirm);

SetConfirm::SetConfirm(const char *name, int kind) : ::cMessage(name,kind)
{
    this->PIBattr_var = 0;
    this->status_var = 0;
}

SetConfirm::SetConfirm(const SetConfirm& other) : ::cMessage(other)
{
    copy(other);
}

SetConfirm::~SetConfirm()
{
}

SetConfirm& SetConfirm::operator=(const SetConfirm& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SetConfirm::copy(const SetConfirm& other)
{
    this->PIBattr_var = other.PIBattr_var;
    this->status_var = other.status_var;
}

void SetConfirm::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->PIBattr_var);
    doPacking(b,this->status_var);
}

void SetConfirm::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->PIBattr_var);
    doUnpacking(b,this->status_var);
}

unsigned short SetConfirm::getPIBattr() const
{
    return PIBattr_var;
}

void SetConfirm::setPIBattr(unsigned short PIBattr)
{
    this->PIBattr_var = PIBattr;
}

unsigned short SetConfirm::getStatus() const
{
    return status_var;
}

void SetConfirm::setStatus(unsigned short status)
{
    this->status_var = status;
}

class SetConfirmDescriptor : public cClassDescriptor
{
  public:
    SetConfirmDescriptor();
    virtual ~SetConfirmDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SetConfirmDescriptor);

SetConfirmDescriptor::SetConfirmDescriptor() : cClassDescriptor("SetConfirm", "cMessage")
{
}

SetConfirmDescriptor::~SetConfirmDescriptor()
{
}

bool SetConfirmDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SetConfirm *>(obj)!=NULL;
}

const char *SetConfirmDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SetConfirmDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int SetConfirmDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SetConfirmDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "PIBattr",
        "status",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int SetConfirmDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='P' && strcmp(fieldName, "PIBattr")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SetConfirmDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *SetConfirmDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PhyPIB_Attributes";
            return NULL;
        case 1:
            if (!strcmp(propertyname,"enum")) return "PhyPIB_Status";
            return NULL;
        default: return NULL;
    }
}

int SetConfirmDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SetConfirm *pp = (SetConfirm *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SetConfirmDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SetConfirm *pp = (SetConfirm *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPIBattr());
        case 1: return ulong2string(pp->getStatus());
        default: return "";
    }
}

bool SetConfirmDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SetConfirm *pp = (SetConfirm *)object; (void)pp;
    switch (field) {
        case 0: pp->setPIBattr(string2ulong(value)); return true;
        case 1: pp->setStatus(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SetConfirmDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *SetConfirmDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SetConfirm *pp = (SetConfirm *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


