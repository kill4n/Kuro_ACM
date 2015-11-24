#include "joystick_helper.h"

joystick_helper::joystick_helper():num_of_axis(0),
    num_of_buttons(0), isRunning(false)
{
}

joystick_helper::~joystick_helper()
{
    printf("Cerrando_hilo joystick\r\n");
    isRunning = false;
    this->WaitForInternalThreadToExit();
    printf("Cerrando joystick\r\n");
}

int joystick_helper::openJoy()
{
    if( ( joy_fd = open( JOY_DEV , O_RDONLY)) == -1 )
    {
        printf( "No se pudo abrir Joystick\n" );
        return -1;
    }
    else {
        printf("Se pudo conectar el Joystick\n");
        ioctl( joy_fd, JSIOCGAXES, &num_of_axis );
        ioctl( joy_fd, JSIOCGBUTTONS, &num_of_buttons );
        ioctl( joy_fd, JSIOCGNAME(80), &name_of_joystick );

        axis = (int *) calloc( num_of_axis, sizeof( int ) );
        button = (char *) calloc( num_of_buttons, sizeof( char ) );

        printf("Joystick detectado: %s\n\t%d ejes\n\t%d botones\n\n"
               , name_of_joystick
               , num_of_axis
               , num_of_buttons );

        fcntl( joy_fd, F_SETFL, O_NONBLOCK );	/* use non-blocking mode */
    }
    isRunning=true;
    printf("joystick inicio {%d}\r\n",isRunning);
}

int joystick_helper::closeJoy()
{
    close(joy_fd);	/* Cerrar el Joystick */
}

int joystick_helper::readJoy()
{
    /* read the joystick state */
    read(joy_fd, &js, sizeof(struct js_event));

    /* see what to do with the event */
    switch (js.type & ~JS_EVENT_INIT)
    {
    case JS_EVENT_AXIS:
        axis   [ js.number ] = js.value;
        break;
    case JS_EVENT_BUTTON:
        button [ js.number ] = js.value;
        break;
    }

    joyAx.AxisVel = axis[1];
    joyAx.AxisDir = axis[3];
    fflush(stdout);
}

void joystick_helper::setCallback(void(*cb)(JOY_STR))
{
    callback = cb;
}

void joystick_helper::InternalThreadEntry()
{
    printf("Hola  sd desde Hilo {%d}\r\n",isRunning);
    while (isRunning) {
        readJoy();
        this->callback(joyAx);        
        usleep(1000);

    }
    this->closeJoy();
}

