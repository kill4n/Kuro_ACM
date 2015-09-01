#ifndef M54_PRO_H
#define M54_PRO_H

namespace Thor {
    enum CONTROL_TABLE{
        PKT_HEADER0,
        PKT_HEADER1,
        PKT_HEADER2,
        PKT_RESERVED,
        PKT_ID,
        PKT_LENGTH_L,
        PKT_LENGTH_H,
        PKT_INSTRUCTION,
        PKT_PARAMETER
    };


    class M54_PRO
    {
    public:
        M54_PRO();
    };
}
#endif // M54_PRO_H
