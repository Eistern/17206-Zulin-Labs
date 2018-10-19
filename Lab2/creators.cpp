#include "creators.h"

pushCreator _push;
popCreator _pop;
addCreator _add;
subCreator _sub;
mulCreator _mul;
divCreator _div;
sqrtCreator _sqrt;
defineCreator _define;

const std::map<std::string, cmdCreator*> cmdCreator::_creatorArray = { {"PUSH", &_push},
                                                                       {"POP", &_pop},
                                                                       {"+",  &_add},
                                                                       {"-", &_sub},
                                                                       {"*", &_mul},
                                                                       {"/", &_div},
                                                                       {"SQRT", &_sqrt},
                                                                       {"DEFINE", &_define}
};