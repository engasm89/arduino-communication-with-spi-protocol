#include <stdio.h> // Include I/O for SPI logs
#include <unistd.h> // Include POSIX sleep for delays

// Simulated Arduino SPI state
static int ar_spi_ok = 0; // Track Arduino SPI readiness
static int ar_spi_speed = 1000000; // Simulated SPI speed (Hz)

// Initialize Arduino SPI as master (stub)
int ar_spi_init(void) { // Function to initialize Arduino SPI
  ar_spi_ok = 1; // Mark SPI ready
  printf("Arduino SPI Master init speed=%dHz\n", ar_spi_speed); // Log init with speed
  return ar_spi_ok; // Return status
} // End ar_spi_init

// Transfer a byte over SPI (stub)
int ar_spi_transfer(unsigned char tx, unsigned char *rx) { // Function for SPI transfer
  if (!ar_spi_ok) return 0; // Fail if not ready
  *rx = (unsigned char)(tx ^ 0x0F); // Simulate response by XOR
  printf("Arduino SPI TX=0x%02X RX=0x%02X\n", tx, *rx); // Log
  return 1; // Success
} // End ar_spi_transfer

// Transfer a block of bytes over SPI
void ar_spi_transfer_block(const unsigned char *tx, unsigned char *rx, int len) { // Block transfer
  for (int i = 0; i < len; ++i) { // Iterate
    ar_spi_transfer(tx[i], &rx[i]); // Transfer one byte
    usleep(50000); // 50ms per byte for simulation
  } // End block
}

// Entry demonstrating Arduino SPI communication
int main(void) { // Begin main
  printf("Arduino Communication with SPI Protocol\n"); // Title
  ar_spi_init(); // Initialize SPI
  unsigned char rx = 0; // Prepare RX var
  for (unsigned char tx = 0x20; tx < 0x24; ++tx) { // Loop TX bytes
    ar_spi_transfer(tx, &rx); // Transfer
    usleep(250000); // Delay 250 ms
  } // End loop
  unsigned char txb[4] = {0xAA,0xBB,0xCC,0xDD}; // Example TX block
  unsigned char rxb[4] = {0}; // RX block buffer
  ar_spi_transfer_block(txb, rxb, 4); // Block transfer demo
  return 0; // Exit success
} // End main

