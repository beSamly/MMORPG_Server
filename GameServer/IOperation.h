#pragma once

class IOperation {

private:
    /*wptr<Champion> owner;
    wptr<Champion> target;*/
    int duration = 0;

public:

public:
    virtual void OnExecute() abstract;
    virtual void OnEnd() abstract;
    virtual void OnTick() abstract;
};