typedef struct{
    float desired;
    float error;
    float previous_error;
    float integral;
    float integrate_limit;
    float Kp, Ki, Kd;
} PID;

void PID_Init(PID *);

void PID_Set_Kp(PID *, float);
void PID_Set_Ki(PID *, float);
void PID_Set_Kd(PID *, float);

void PID_Set_Target(PID *, float);

void PID_Set_IntegrateLimit(PID *, float);

void Update_PID(PID *, float current, float *output);
void Update_PID_DerivKnown(PID *, float current, float derivative, float *output);
