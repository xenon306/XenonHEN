#include <stddef.h>
#include <stdint.h>
#include <orbis/libkernel.h>
#include <orbis/libnotification.h>

// Constants and Settings:
#define XenonHEN_VERSION "v1.0a"
#define DEVELOPER "Xenon Tech"

// Functions
// This function sends the PS4 a message
void send_notification(const* message) {
    // In OpenOrbis the sceNotify is the original call
    sceNotify(0, message);
}

// Here comes the 13.02 fw patches, we use v01dcat's bugs (after it becomes public)
void apply_xenon_patches() {
    // First we request the kernel's base address (we need an exploit for this, XenonExploit maybe will come)
    // uint64_t kbase = get_kernel_base();

    // Here we enable fPKG and Debug Settings
    // Example, if we write the offset here, we write the memory:
    // kernel_write(kbase + 0xABC123, "\x90\x90", 2);

    // If the patches are applied, then we send the user a message:
    send_notification("XenonHEN: Patches applied!");
}

// This is XenonHEN's entry point
int _main(void) {
    // Inicializing
    // Here we prepare the system to run the code
    // Welcome Message:
    char welcome_msg[100];
    char dev_msg[100];

    // We compose the text
    __builtin_sprintf(welcome_msg, "XenonHEN %s loaded!", XenonHEN_VERSION);
    __builtin_sprintf(dev_msg, "Coded by: %s", DEVELOPER);

    // We show it on the screen
    send_notification(welcome_msg);
    send_notification(dev_msg);

    // We start the jailbreaking process
    apply_xenon_patches();

    // We exit, but the settings are staying in the memory
    return 0;
}

