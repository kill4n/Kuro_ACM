#include "joystick_helper.h"

joystick_helper::joystick_helper():num_of_axis(0),
    num_of_buttons(0)
{
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

    /* print the results */
    printf( "X: %6d  Y: %6d  ", axis[0], axis[1] );

    if( num_of_axis > 2 )
        printf("Z: %6d  ", axis[2] );

    if( num_of_axis > 3 )
        printf("R: %6d  ", axis[3] );

    for( x=0 ; x<num_of_buttons ; ++x )
        printf("B%d: %d  ", x, button[x] );

    printf("  \r");
    fflush(stdout);
}

