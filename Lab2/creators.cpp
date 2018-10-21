#include "creators.h"

PushCreator _push;
PopCreator _pop;
PrintCreator _print;
AddCreator _add;
SubCreator _sub;
MulCreator _mul;
DivCreator _div;
SqrtCreator _sqrt;
DefineCreator _define;

const std::map<std::string, CmdCreator*> CmdCreator::_creatorArray = { {"PUSH", &_push}, // NOLINT
                                                                       {"POP", &_pop},
                                                                       {"PRINT", &_print},
                                                                       {"+",  &_add},
                                                                       {"-", &_sub},
                                                                       {"*", &_mul},
                                                                       {"/", &_div},
                                                                       {"SQRT", &_sqrt},
                                                                       {"DEFINE", &_define}
};