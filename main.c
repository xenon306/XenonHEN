#include <stddef.h>
#include <stdint.h>
#include <orbis/libkernel.h>
#include <orbis/libnotification.h>

// Constants and Settings:
#define TARGET_FW 0x0D02 // This is the 13.02 firmware's hexadecimal code
#define XenonHEN_VERSION "v1.0a"

void send_notification(const char* message) {
    sceNotify(0, message);
}

// This function requests the exact firmware version
int get_fw_version() {
    char sdk_ver[20];
    int mib[2];
    size_t len;

    // The system's internal call to request the firmware version
    // Note: In OpenOrbis, we use sceKernelGetSystemSwVersion
    int version = 0;
    size_t v_len = sizeof(version);
    sysctlbyname("kern.sdk_version", &version, &v_len, NULL, 0);

    return (version >>16); // We give back the main version, for example (0x0D02)
}

int _main(void) {
    // Notification
    send_notification("XenonHEN Initializing...");

    // We check the version
    int current_fw = get_fw_version();

    if (current_fw != TARGET_FW) {
        char error_msg[100];
        __builtin_sprintf(error_msg, "Error: FW %04X not supported! XenonHEN needs 13.02.", current_fw);
        send_notification(error_msg);
        return -1; // We stop XenonHEN, because its not safe to run if the firmware is not supported
    }

    // If the version is matching, we can continue running XenonHEN
    send_notification("Firmware 13.02 detected!");
    send_notification("XenonHEN v1.0a Loaded! Coded by: Xenon");

    // Here is going to be the future patches
    // apply_1302_patches();

    return 0;
}
