//  Copyright 2023 Shipilov Artem

#ifndef MODULES_HASHMAP_INCLUDE_HASHMAP_H_
#define MODULES_HASHMAP_INCLUDE_HASHMAP_H_

#include <string>
#include <iostream>

class TabRecord {
 protected:
    std::string Key;
    double* Data;

 public:
    TabRecord(std::string key_, double data_) {
        Key = key_;
        Data = new double(data_);
    }
    explicit TabRecord(std::string key_) {
        Key = key_;
        Data = nullptr;
    }
    TabRecord(const TabRecord& Tab_) {
        Key = Tab_.Key;
        Data = new double(*(Tab_.Data));
    }
    ~TabRecord() { delete Data; }

    void SetKey(const std::string key_) { Key = key_; }
    std::string GetKey() const { return Key; }

    void SetData(double data_) { Data = new double(data_); }
    double* GetData() const { return Data; }

    TabRecord& operator=(const TabRecord& Tab_) {
        Data = new double(*(Tab_.Data));
        Key = Tab_.Key;
        return *this;
    }
};

class hashmap {
 public:
    int DataCount;
    TabRecord** pRecs;
    int TabSize;
    int CurrPos;
    int HashStep;
    TabRecord* pMark;
    int FreePos;

    explicit hashmap(int Size_ = 40, int Step_ = 7);
    hashmap(const hashmap& Table_);
    ~hashmap() {}

    int HashFunc(const std::string key_);
    int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }

    std::string GetKey() const { return GetKey(1); }
    double* GetData() const { return GetData(1); }
    std::string GetKey(int mode) const;
    double* GetData(int mode) const;

    int GetDataCount() const { return DataCount; }
    int IsEmpty() const { return DataCount == 0; }
    virtual int IsTabEnded() const { return CurrPos >= TabSize; }

    double* FindRecord(const std::string key_);
    void InsRecord(const std::string key_, const double data_);
    void DelRecord(const std::string key_);

    virtual void Reset();
    virtual void GoNext();

    virtual int IsFull() const { return DataCount >= TabSize; }
    int GetTabSize() const { return TabSize; }

    friend std::ostream& operator<<(std::ostream& os, hashmap& tab) {
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext()) {
            os << "|" << *tab.GetData() <<
                "|" << tab.GetKey() << "|" << std::endl;
        }
        return os;
    }
};

#endif  // MODULES_HASHMAP_INCLUDE_HASHMAP_H_
