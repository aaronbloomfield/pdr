#ifndef OBJECTCELL_H
#define OBJECTCELL_H

template <typename Object>
class ObjectCell {
public:
    ObjectCell(const Object & initValue = Object()) : storedValue(initValue) {
    }

    const Object & getValue() const {
        return storedValue;
    }

    void setValue(const Object & val) {
        storedValue = val;
    }

private:
    Object storedValue;
};

#endif
