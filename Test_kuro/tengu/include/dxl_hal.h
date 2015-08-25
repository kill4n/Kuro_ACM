#ifndef _DYNAMIXEL_HAL_HEADER
#define _DYNAMIXEL_HAL_HEADER

#ifdef __cplusplus
extern "C" {
#endif


double  dxl_hal_get_curr_time();

int     dxl_hal_open( void** port, int dev_index, float baudrate );
void    dxl_hal_close( void** port );
void    dxl_hal_clear( void* port );
int     dxl_hal_change_baudrate( void* port, float baudrate );
int     dxl_hal_read( void* port, void *buf, unsigned int count );
int     dxl_hal_write( void* port, const void *buf, unsigned int count );


#ifdef __cplusplus
}
#endif

#endif
