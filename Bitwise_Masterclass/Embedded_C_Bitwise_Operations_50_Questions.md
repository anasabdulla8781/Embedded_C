# 50 Practical Bitwise Operations Questions in Embedded C

**Level:** Experienced embedded engineer — approximately 6 years of experience

The goal is not to practise basic `AND`, `OR`, `XOR`, and shift operations in isolation. These 50 questions are designed around real firmware work: register manipulation, peripheral drivers, interrupt handling, communication protocols, fault diagnostics, memory-efficient data processing, and debugging.

The questions assume you are comfortable with C programming and want to strengthen your ability to use bitwise operations safely and efficiently in production embedded firmware.

## Curriculum structure

1. **Register manipulation and field operations** — Q1–Q8  
   Set, clear, toggle, mask, extract and update fields.
2. **Bitfields, encoding and data packing** — Q9–Q15  
   Packets, status words, flags and compact representations.
3. **Integer promotions, signedness and C pitfalls** — Q16–Q22  
   Undefined behavior, integer widths and safe shifts.
4. **Interrupts, concurrency and atomicity** — Q23–Q28  
   Shared flags, read-modify-write races and critical sections.
5. **Peripheral drivers and hardware registers** — Q29–Q35  
   GPIO, timers, ADC, I²C/SPI and write-one-to-clear registers.
6. **Protocols, diagnostics and bit algorithms** — Q36–Q42  
   CRC, parity, error flags, bitmaps and lookup techniques.
7. **Code review, optimization and debugging** — Q43–Q50  
   Robust APIs, portability, performance and real firmware defects.

Each question includes the practical task, the concepts to cover, and the expected outcome. Some questions deliberately involve multiple valid approaches so you can evaluate trade-offs rather than just produce working code.

---

## Section 1 — Register manipulation and field operations

*Q1–Q8 · Foundation for writing reliable peripheral drivers*

### Q1. Modify a single bit without affecting other bits

**Scenario:** A control register contains configuration for several peripherals. You must enable bit 5 while preserving every other bit.

**Task:** Write reusable C code to set bit 5, clear bit 5, and toggle bit 5.

Checklist:
- [ ] Implement set, clear and toggle operations.
- [ ] Explain why `|`, `& ~` and `^` are used.
- [ ] Demonstrate that unrelated bits remain unchanged.
- [ ] Use an unsigned integer type and a bit-position macro.

**Expected outcome:** Reliable single-bit register manipulation.

### Q2. Update a multi-bit field

**Scenario:** A timer's control register contains a 3-bit clock prescaler field at bits 4–6.

**Task:** Write a function that changes the prescaler value without modifying other register fields.

Checklist:
- [ ] Construct the field mask.
- [ ] Clear the old field before inserting the new value.
- [ ] Shift the new value into position.
- [ ] Reject values that do not fit into 3 bits.
- [ ] Explain why simply OR-ing the new value into the register is incorrect.

**Expected outcome:** Safe masked field updates.

### Q3. Extract and decode a register field

**Scenario:** A peripheral's status register stores a 4-bit operating mode at bits 8–11.

**Task:** Extract the mode and convert it into meaningful enumerated states.

Checklist:
- [ ] Apply the mask and right shift.
- [ ] Define valid mode values.
- [ ] Handle reserved and unsupported values.
- [ ] Avoid accidentally including unrelated status bits.

**Expected outcome:** Robust register decoding.

### Q4. Write a generic bit-manipulation API

**Scenario:** Your firmware uses the same register operations across GPIO, timer and communication drivers.

**Task:** Design reusable functions or macros for setting, clearing, toggling, testing and updating bits.

Checklist:
- [ ] Define a consistent API.
- [ ] Evaluate macro type safety and repeated evaluation.
- [ ] Handle bit positions outside the supported width.
- [ ] Decide when a `static inline` function is preferable.
- [ ] Discuss volatile-qualified register pointers.

**Expected outcome:** Maintainable, reusable embedded C utilities.

### Q5. Configure multiple independent control bits

**Scenario:** A peripheral must be enabled, its interrupt enabled, and its low-power mode disabled through one control register.

**Task:** Implement the configuration while preserving unrelated bits.

Checklist:
- [ ] Set multiple selected bits in one operation.
- [ ] Clear a different group of bits.
- [ ] Combine masks without confusing bit positions with bit values.
- [ ] Compare sequential read-modify-write operations with a combined operation.

**Expected outcome:** Correct multi-bit configuration.

### Q6. Test whether multiple flags satisfy a condition

**Scenario:** A driver should proceed only when both `READY` and `CALIBRATED` are set, and `FAULT` is clear.

**Task:** Implement the condition using masks.

Checklist:
- [ ] Check whether all required flags are set.
- [ ] Check whether any prohibited flag is set.
- [ ] Distinguish `(status & mask) == mask` from `(status & mask) != 0`.
- [ ] Explain why logical operators and bitwise operators are not interchangeable.

**Expected outcome:** Correct flag-condition logic.

### Q7. Update one field from a configuration structure

**Scenario:** A device has a 16-bit configuration word containing mode, data width, parity and stop-bit fields.

**Task:** Implement independent setters for each field so changing parity never corrupts the mode or data width.

Checklist:
- [ ] Define non-overlapping masks and shifts.
- [ ] Validate each field's allowed range.
- [ ] Ensure setters preserve all unrelated bits.
- [ ] Create a test that changes fields in different orders.

**Expected outcome:** Reliable configuration-word management.

### Q8. Implement a register reset while preserving reserved bits

**Scenario:** A register contains documented writable fields alongside reserved bits that must retain their required values.

**Task:** Reset only the documented writable fields.

Checklist:
- [ ] Distinguish a full-register write from a masked update.
- [ ] Identify when reserved bits must be written as zero or one.
- [ ] Check the peripheral's documented reset and write behavior.
- [ ] Explain why preserving reserved bits by reading them back is not universally correct.

**Expected outcome:** Datasheet-driven register programming.

---

## Section 2 — Bitfields, encoding and data packing

*Q9–Q15 · Compact representations used in drivers and communication stacks*

### Q9. Pack multiple sensor values into a 32-bit word

**Scenario:** You must encode a 4-bit sensor ID, a 4-bit status code, a 12-bit measurement and a 12-bit counter into one 32-bit word.

**Task:** Pack the four fields and then unpack them.

Checklist:
- [ ] Assign exact bit positions.
- [ ] Mask inputs before shifting.
- [ ] Decode each field independently.
- [ ] Validate boundary values.
- [ ] Explain how to prevent one field from overlapping another.

**Expected outcome:** Reliable data packing and unpacking.

### Q10. Decode a communication protocol header

**Scenario:** A received 16-bit header contains a 3-bit message type, a 5-bit destination address and an 8-bit payload length.

**Task:** Extract the header fields and reject invalid messages.

Checklist:
- [ ] Decode fields from the specified bit positions.
- [ ] Validate message type and address.
- [ ] Check payload length against buffer capacity.
- [ ] Handle reserved encodings.
- [ ] Separate bit extraction from protocol validation.

**Expected outcome:** Robust protocol parsing.

### Q11. Pack and unpack signed sensor values

**Scenario:** A device transmits a signed 12-bit temperature measurement inside a 16-bit word.

**Task:** Decode the 12-bit two's-complement value into a suitable signed C type.

Checklist:
- [ ] Extract the 12-bit raw value.
- [ ] Detect the sign bit.
- [ ] Sign-extend correctly.
- [ ] Test zero, maximum positive, minimum negative and negative one.
- [ ] Avoid relying on implementation-defined signed shifts.

**Expected outcome:** Correct signed-value decoding.

### Q12. Convert between little-endian and big-endian data

**Scenario:** An MCU receives a 32-bit value as four bytes, but the protocol specifies big-endian ordering.

**Task:** Construct the value from the bytes and serialize it back into the required order.

Checklist:
- [ ] Use explicit byte shifts and masks.
- [ ] Avoid unaligned pointer casts.
- [ ] Avoid strict-aliasing and host-endianness assumptions.
- [ ] Test with a known pattern such as `0x12345678`.
- [ ] Distinguish byte order from bit order.

**Expected outcome:** Portable byte-level data handling.

### Q13. Implement a configurable status-word decoder

**Scenario:** A 32-bit diagnostic word contains 12 independent fault flags, 4 warning flags, an 8-bit subsystem identifier and reserved bits.

**Task:** Extract and report all meaningful fields.

Checklist:
- [ ] Define named masks.
- [ ] Decode multiple simultaneous faults.
- [ ] Ignore or report reserved bits according to the specification.
- [ ] Avoid magic numbers.
- [ ] Write tests for overlapping combinations of active faults.

**Expected outcome:** Structured diagnostic decoding.

### Q14. Maintain a compact event bitmap

**Scenario:** A controller tracks whether 32 separate events have occurred using a single 32-bit word.

**Task:** Implement event set, clear, test and reset-all operations.

Checklist:
- [ ] Map event IDs to bit positions.
- [ ] Handle invalid event IDs safely.
- [ ] Find all active events.
- [ ] Discuss the difference between clearing one event and clearing all events.
- [ ] Consider concurrent updates from interrupts.

**Expected outcome:** Memory-efficient event tracking.

### Q15. Implement a bitstream reader

**Scenario:** A custom serial protocol packs variable-width fields that do not necessarily start on byte boundaries.

**Task:** Write a function that reads an unsigned field of up to 16 bits starting at an arbitrary bit offset in a byte buffer.

Checklist:
- [ ] Handle fields crossing byte boundaries.
- [ ] Define whether bit offset zero means the MSB or LSB.
- [ ] Validate buffer length and field width.
- [ ] Avoid out-of-range shifts.
- [ ] Test offsets near byte boundaries and the end of the buffer.

**Expected outcome:** Safe bit-level protocol parsing.

---

## Section 3 — Integer promotions, signedness and C pitfalls

*Q16–Q22 · Essential for production-quality embedded C*

### Q16. Diagnose an incorrect result from an 8-bit shift

**Scenario:** A developer writes:

```c
uint8_t value = 0x80U;
uint8_t result = value << 1;
```

**Task:** Explain the actual C expression behavior and how to write a safe operation for an 8-bit result.

Checklist:
- [ ] Explain integer promotions.
- [ ] Identify the type of the shift expression.
- [ ] Explain assignment conversion and truncation.
- [ ] Distinguish a defined shift from a potentially undefined shift.
- [ ] Demonstrate the result on a typical embedded C implementation.

**Expected outcome:** Understanding of integer promotions and shift semantics.

### Q17. Audit unsafe shift expressions

**Scenario:** A register helper accepts a variable shift count supplied by configuration data.

**Task:** Identify and fix defects in expressions involving negative shift counts, counts equal to the type width, and shifts of signed values.

Checklist:
- [ ] Identify undefined behavior.
- [ ] Validate the shift count before performing the operation.
- [ ] Use unsigned operands of a known width.
- [ ] Handle the zero-bit and maximum-bit cases.
- [ ] Explain why a cast alone does not fix an invalid shift count.

**Expected outcome:** Safe, portable shift operations.

### Q18. Build a full-width bit mask safely

**Scenario:** A driver needs a mask containing `n` low-order bits, where `n` may equal 32 for a 32-bit mask.

**Task:** Implement a safe mask-generation function.

Checklist:
- [ ] Handle `n == 0`.
- [ ] Handle `n == 32`.
- [ ] Avoid shifting by the operand width.
- [ ] Use fixed-width unsigned types.
- [ ] Validate out-of-range input.

**Expected outcome:** Boundary-safe mask generation.

### Q19. Investigate signed right-shift behavior

**Scenario:** A firmware algorithm uses right shifts to scale signed ADC calibration offsets.

**Task:** Determine whether the implementation is portable and replace unsafe assumptions where necessary.

Checklist:
- [ ] Explain logical versus arithmetic right shift.
- [ ] Explain the implementation-defined behavior of right-shifting a negative signed value in C.
- [ ] Consider rounding for negative values.
- [ ] Select a suitable replacement when exact division semantics are required.
- [ ] Test positive and negative boundary values.

**Expected outcome:** Portable signed arithmetic and scaling.

### Q20. Fix a signed bitwise-complement bug

**Scenario:** The code uses `~mask` to clear selected bits from a register, but `mask` has a signed integer type.

**Task:** Explain integer conversions and make the operation type-correct.

Checklist:
- [ ] Explain why `~` flips every bit of the operand's promoted type.
- [ ] Use a suitable unsigned type for masks.
- [ ] Ensure the mask width matches the destination register.
- [ ] Check the result of mixed signed and unsigned expressions.
- [ ] Verify behavior using fixed-width integer types.

**Expected outcome:** Correct mask typing and conversion control.

### Q21. Review a bitwise optimization that changes arithmetic behavior

**Scenario:** A developer replaces division by two with a right shift to improve performance.

**Task:** Determine when the replacement is valid and when it changes the result.

Checklist:
- [ ] Compare signed and unsigned operands.
- [ ] Check negative odd values.
- [ ] Explain rounding toward zero versus shift behavior.
- [ ] Consider compiler optimization capabilities.
- [ ] Prioritize correctness over assumed performance gains.

**Expected outcome:** Sound arithmetic optimization decisions.

### Q22. Make bit manipulation portable across integer widths

**Scenario:** A driver is built for an 8-bit MCU, a 16-bit MCU and a 32-bit MCU.

**Task:** Audit its masks, shifts and constant definitions for portability.

Checklist:
- [ ] Use `<stdint.h>` types appropriately.
- [ ] Use `UINT8_C`, `UINT16_C`, `UINT32_C` or suitable unsigned constants where appropriate.
- [ ] Check assumptions about `int`, `CHAR_BIT` and register widths.
- [ ] Avoid assuming all platforms have the same integer promotion behavior.
- [ ] Explain which requirements are guaranteed by the C standard and which depend on the target.

**Expected outcome:** Portable embedded C bit manipulation.

---

## Section 4 — Interrupts, concurrency and atomicity

*Q23–Q28 · Where correct bitwise syntax can still produce incorrect firmware*

### Q23. Handle flags shared between an ISR and the main loop

**Scenario:** A UART interrupt sets receive-event flags, and the main loop processes them.

**Task:** Design a flag-handling mechanism that avoids losing events.

Checklist:
- [ ] Use masks to represent independent events.
- [ ] Explain why `volatile` alone does not guarantee atomicity.
- [ ] Identify races between reading, processing and clearing flags.
- [ ] Consider a critical section or suitable atomic operations.
- [ ] Explain whether multiple occurrences of one event can be represented by a single bit.

**Expected outcome:** Correct ISR-to-main-loop communication.

### Q24. Prevent a read-modify-write race

**Scenario:** An ISR and a task independently update different bits of the same software status word.

**Task:** Demonstrate how one update can overwrite the other and redesign the update mechanism.

Checklist:
- [ ] Trace the interleaving of two updates.
- [ ] Identify the read-modify-write sequence.
- [ ] Evaluate interrupt masking and atomic operations.
- [ ] Consider whether a single-writer design is preferable.
- [ ] Distinguish atomic bit operations from atomic whole-word operations.

**Expected outcome:** Race-free shared-state updates.

### Q25. Understand atomicity of peripheral register writes

**Scenario:** Two execution contexts need to set different bits in a GPIO output register.

**Task:** Compare ordinary read-modify-write code with hardware-supported atomic set/reset registers.

Checklist:
- [ ] Explain why a volatile register access does not make the complete operation atomic.
- [ ] Identify hardware atomic set/reset mechanisms where available.
- [ ] Determine when a critical section is necessary.
- [ ] Consider other contexts, including DMA and other bus masters.
- [ ] Respect the target MCU's documented register semantics.

**Expected outcome:** Safe peripheral register updates under concurrency.

### Q26. Implement a lock-free event flag word

**Scenario:** Several tasks publish independent event flags to a consumer task.

**Task:** Design a flag word using C11 atomic operations, or explain an equivalent target-specific approach where C11 atomics are unavailable.

Checklist:
- [ ] Use atomic fetch-OR or an equivalent atomic update.
- [ ] Retrieve and clear pending flags without losing concurrent events.
- [ ] Choose appropriate memory ordering where relevant.
- [ ] Explain the difference between atomicity and synchronization.
- [ ] Consider whether the target's atomic implementation is suitable for ISR use.

**Expected outcome:** Correct atomic event publication and consumption.

### Q27. Diagnose a lost interrupt event

**Scenario:** A peripheral status bit becomes set, but the firmware occasionally misses the event after clearing the status register.

**Task:** Investigate the bit-level logic and the hardware's event-clearing behavior.

Checklist:
- [ ] Trace the order of reading, handling and clearing flags.
- [ ] Check whether the flag is read-to-clear, write-one-to-clear or cleared by another action.
- [ ] Consider a new event arriving during processing.
- [ ] Design a recovery or recheck strategy.
- [ ] Verify the exact peripheral documentation.

**Expected outcome:** Reliable interrupt-event handling.

### Q28. Design a timeout and fault bitmask for an RTOS

**Scenario:** A FreeRTOS application must track independent faults from a sensor task, communication task and watchdog-monitor task.

**Task:** Design a shared fault mask with safe update and recovery operations.

Checklist:
- [ ] Assign unique bits to fault categories.
- [ ] Set and clear faults without overwriting other faults.
- [ ] Decide which task owns each fault bit.
- [ ] Consider task synchronization and atomic updates.
- [ ] Define how fault recovery and fault history differ.

**Expected outcome:** A dependable firmware fault-management mechanism.

---

## Section 5 — Peripheral drivers and hardware registers

*Q29–Q35 · Practical register-level programming for STM32-class MCUs and similar targets*

### Q29. Configure GPIO mode and output type

**Scenario:** Configure one STM32 GPIO pin as an alternate-function output with the required output type and pull-up setting.

**Task:** Update the relevant GPIO registers using masks and shifts.

Checklist:
- [ ] Calculate the pin's field position.
- [ ] Update the correct two-bit mode field.
- [ ] Configure output type and pull resistors.
- [ ] Set the correct alternate-function nibble.
- [ ] Preserve every unrelated pin configuration.
- [ ] Verify the configuration against the target MCU reference manual.

**Expected outcome:** Register-level GPIO configuration without collateral changes.

### Q30. Configure a timer's prescaler and auto-reload fields

**Scenario:** A timer configuration word contains prescaler and auto-reload values that must be updated for a new sampling rate.

**Task:** Implement the field updates and explain the impact on the timer's resulting frequency.

Checklist:
- [ ] Calculate and insert field values correctly.
- [ ] Validate register-width limits.
- [ ] Distinguish the prescaler register from the auto-reload register.
- [ ] Consider when an update event is required.
- [ ] Handle any required synchronization or preload behavior.

**Expected outcome:** Correct timer configuration and timing calculations.

### Q31. Decode ADC status and sample data

**Scenario:** An ADC status register contains end-of-conversion, overrun and error flags, while the data register holds a 12-bit conversion result.

**Task:** Decode the status and retrieve the sample safely.

Checklist:
- [ ] Test individual and combined status bits.
- [ ] Extract the 12-bit sample.
- [ ] Understand whether reading the data register clears any flags.
- [ ] Handle overrun and conversion errors.
- [ ] Distinguish a raw ADC value from a converted physical measurement.

**Expected outcome:** Reliable ADC status handling.

### Q32. Implement a register-level I²C status decoder

**Scenario:** Your I²C driver reads a status register with flags for start detection, address matching, transfer completion, NACK and bus errors.

**Task:** Decode the current status and determine the next driver state.

Checklist:
- [ ] Define named masks for each status flag.
- [ ] Identify valid combinations and event ordering.
- [ ] Account for flags that must be cleared using special sequences.
- [ ] Handle simultaneous error and completion conditions.
- [ ] Separate status decoding from state-machine transitions.

**Expected outcome:** Robust I²C driver state handling.

### Q33. Build an SPI control-register configuration function

**Scenario:** An SPI peripheral requires a specific clock polarity, clock phase, data width, bit order and master/slave setting.

**Task:** Build a configuration function that updates only the relevant fields.

Checklist:
- [ ] Define masks and enumerated configuration values.
- [ ] Validate the requested configuration.
- [ ] Prevent overlapping fields from being corrupted.
- [ ] Determine which settings may only be changed while the peripheral is disabled.
- [ ] Verify that the resulting register values match the requested SPI mode.

**Expected outcome:** Reliable SPI configuration.

### Q34. Handle write-one-to-clear (W1C) status registers

**Scenario:** A hardware status register clears a flag when you write `1` to its bit position. Writing `0` leaves the flag unchanged.

**Task:** Clear one selected flag without unintentionally clearing other pending flags.

Checklist:
- [ ] Explain why ordinary read-modify-write logic can be dangerous.
- [ ] Write the correct value directly to the W1C register.
- [ ] Avoid writing back unrelated bits read from the register.
- [ ] Distinguish W1C from write-zero-to-clear and ordinary writable registers.
- [ ] Test scenarios with multiple pending flags.

**Expected outcome:** Correct handling of hardware status registers.

### Q35. Modify a hardware register with reserved and self-clearing fields

**Scenario:** A control register contains ordinary configuration bits, reserved bits and a command bit that clears itself after starting an operation.

**Task:** Implement a safe command-and-configuration update.

Checklist:
- [ ] Identify ordinary, reserved and self-clearing fields.
- [ ] Follow documented required values for reserved bits.
- [ ] Avoid replaying command bits during unrelated updates.
- [ ] Check whether writes trigger side effects.
- [ ] Explain why not every register is suitable for a generic read-modify-write helper.

**Expected outcome:** Hardware-aware register manipulation.

---

## Section 6 — Protocols, diagnostics and bit algorithms

*Q36–Q42 · Firmware data integrity, fault detection and compact algorithms*

### Q36. Implement parity generation and checking

**Scenario:** A communication protocol requires even parity over a data word.

**Task:** Generate the parity bit and validate a received word.

Checklist:
- [ ] Calculate parity using XOR operations.
- [ ] Handle different word widths.
- [ ] Test zero, all-ones and alternating-bit patterns.
- [ ] Explain which error patterns parity can and cannot detect.
- [ ] Compare a loop-based approach with a hardware-supported or compiler-supported alternative.

**Expected outcome:** Practical parity implementation and error-detection analysis.

### Q37. Implement CRC calculation using bitwise operations

**Scenario:** A firmware driver needs to calculate a CRC for a data packet when a dedicated CRC peripheral is unavailable.

**Task:** Implement a bitwise CRC algorithm for a specified polynomial and parameter set.

Checklist:
- [ ] Define polynomial, initial value, reflection settings and final XOR.
- [ ] Apply shifts and conditional polynomial XOR correctly.
- [ ] Process bytes in the specified order.
- [ ] Validate against known test vectors.
- [ ] Distinguish CRC-8, CRC-16 and CRC-32 parameters rather than treating each as interchangeable.

**Expected outcome:** Correct software CRC implementation.

### Q38. Find the position of the least significant set bit

**Scenario:** A pending-event mask contains several active events, and the firmware must process the lowest-numbered event first.

**Task:** Find the least significant set-bit position.

Checklist:
- [ ] Handle a zero input.
- [ ] Implement a portable loop-based solution.
- [ ] Evaluate compiler built-ins or hardware instructions where available.
- [ ] Understand the behavior of operations such as `x & (x - 1)`.
- [ ] Compare correctness and execution cost.

**Expected outcome:** Efficient bit scanning for event processing.

### Q39. Count the number of set bits

**Scenario:** A diagnostic module must calculate how many channels are active in a 32-bit status word.

**Task:** Implement a population-count function.

Checklist:
- [ ] Write a portable implementation.
- [ ] Evaluate Brian Kernighan's algorithm.
- [ ] Consider compiler built-ins and hardware instructions.
- [ ] Test zero, all-ones and sparse bit patterns.
- [ ] Explain which implementation is best for a particular MCU and timing requirement.

**Expected outcome:** Efficient bit counting and implementation trade-off analysis.

### Q40. Reverse the bit order of a byte

**Scenario:** A serial communication peripheral requires a bit-reversed representation of each received byte.

**Task:** Implement an 8-bit bit-reversal function.

Checklist:
- [ ] Distinguish bit reversal from byte swapping.
- [ ] Use masks and shifts correctly.
- [ ] Verify asymmetric patterns such as `0x96`.
- [ ] Consider a lookup table versus an arithmetic implementation.
- [ ] Explain how the protocol defines bit transmission order.

**Expected outcome:** Correct bit-order conversion.

### Q41. Detect invalid or inconsistent status combinations

**Scenario:** A device's status word contains `BUSY`, `DONE`, `ERROR` and `RESET_REQUIRED` flags. Some combinations are forbidden.

**Task:** Implement validation logic and report the inconsistent states.

Checklist:
- [ ] Identify valid and invalid flag combinations.
- [ ] Use masks for multi-flag conditions.
- [ ] Account for flags that may legitimately coexist.
- [ ] Write unit tests for every invalid combination.
- [ ] Keep protocol validation separate from the raw bit extraction.

**Expected outcome:** Defensive status-word validation.

### Q42. Manage a resource bitmap

**Scenario:** An embedded scheduler tracks 32 hardware resources. A set bit means a resource is occupied.

**Task:** Implement allocation, release and free-resource search.

Checklist:
- [ ] Find an available resource.
- [ ] Allocate it without changing other bits.
- [ ] Release a resource safely.
- [ ] Handle a full bitmap and invalid resource IDs.
- [ ] Consider concurrency and whether allocation must be atomic.

**Expected outcome:** Practical bitmap-based resource management.

---

## Section 7 — Code review, optimization and debugging

*Q43–Q50 · Senior-level reasoning, production bugs and design trade-offs*

### Q43. Review a macro that modifies a register

**Scenario:** A legacy driver uses this macro:

```c
#define SET_BITS(reg, mask) ((reg) |= (mask))
```

**Task:** Review its safety and redesign the interface where necessary.

Checklist:
- [ ] Explain macro type and side-effect risks.
- [ ] Consider volatile-qualified registers.
- [ ] Evaluate `static inline` functions.
- [ ] Handle masks and register widths consistently.
- [ ] Explain how a generic abstraction can hide hardware-specific semantics.

**Expected outcome:** Better bit-manipulation APIs and code review skills.

### Q44. Diagnose a mask that clears the wrong field

**Scenario:** A driver must clear bits 8–11, but its mask unintentionally clears bits 4–11.

**Task:** Identify the defect, fix the mask and add a regression test.

Checklist:
- [ ] Derive the mask mathematically.
- [ ] Verify the bit positions using hexadecimal representation.
- [ ] Check operator precedence.
- [ ] Test that adjacent fields remain unchanged.
- [ ] Use named constants to reduce future errors.

**Expected outcome:** Systematic mask debugging.

### Q45. Optimize a frequently executed bit-processing loop

**Scenario:** A real-time task scans a 32-bit status word thousands of times per second.

**Task:** Compare a straightforward loop, a bit-clearing algorithm and target-specific compiler built-ins.

Checklist:
- [ ] Compare worst-case iteration counts.
- [ ] Consider the MCU instruction set.
- [ ] Measure generated machine code.
- [ ] Evaluate worst-case execution time rather than average time alone.
- [ ] Preserve defined C behavior and readability.

**Expected outcome:** Evidence-based bitwise optimization.

### Q46. Design a safe register-access abstraction

**Scenario:** Several drivers manipulate memory-mapped registers with different widths and write semantics.

**Task:** Design an abstraction that supports ordinary registers without incorrectly applying the same operations to W1C, read-to-clear or command registers.

Checklist:
- [ ] Define the supported register-access operations.
- [ ] Use appropriate volatile-qualified pointers.
- [ ] Avoid invalid access widths and unintended readbacks.
- [ ] Separate ordinary configuration updates from special hardware actions.
- [ ] Document which operations are atomic and which are not.

**Expected outcome:** Hardware-safe register-access design.

### Q47. Audit code for undefined and implementation-defined behavior

**Scenario:** During a firmware review, you find complex expressions combining signed integers, shifts, masks, complements and implicit conversions.

**Task:** Identify problematic expressions and rewrite them safely.

Checklist:
- [ ] Check shift counts and operand types.
- [ ] Check signed overflow and integer promotions.
- [ ] Identify implementation-defined conversions or behavior.
- [ ] Use compiler warnings and static analysis.
- [ ] Create boundary-focused tests and explain their limits.

**Expected outcome:** Standards-aware C code review.

### Q48. Build a fault-injection test suite for bitwise functions

**Scenario:** A safety-related driver needs evidence that its masks and register helpers work correctly under unusual inputs.

**Task:** Design a systematic test suite for the bit-manipulation utilities.

Checklist:
- [ ] Test zero, all-ones and single-bit inputs.
- [ ] Test the highest supported bit.
- [ ] Test invalid bit positions and out-of-range field values.
- [ ] Test reserved bits and overlapping masks.
- [ ] Use host-side unit tests where practical and hardware-in-the-loop tests where required.

**Expected outcome:** Repeatable verification of bit-level code.

### Q49. Diagnose a real firmware failure involving a register update

**Scenario:** A GPIO output unexpectedly changes when a timer interrupt updates a neighboring control bit. The problem appears only under heavy interrupt load.

**Task:** Investigate the register-access sequence and propose a robust fix.

Checklist:
- [ ] Reconstruct the possible interrupt interleavings.
- [ ] Identify read-modify-write hazards.
- [ ] Check whether the register provides atomic set/reset aliases.
- [ ] Distinguish a software race from a peripheral-specific register behavior.
- [ ] Design a reproducible test and verify the fix.

**Expected outcome:** End-to-end debugging of a bitwise concurrency defect.

### Q50. Design a production-grade bit manipulation module

**Scenario:** You are responsible for a reusable embedded C library shared by multiple MCU projects and reviewed by a team of experienced firmware engineers.

**Task:** Design and implement the module, including APIs, tests and usage documentation.

Checklist:
- [ ] Provide set, clear, toggle and test operations.
- [ ] Provide field extraction, insertion and mask-generation helpers.
- [ ] Support fixed-width unsigned types and validate input ranges.
- [ ] Address ISR concurrency and hardware-register semantics explicitly.
- [ ] Define portability and coding-standard requirements.
- [ ] Provide unit tests, edge cases and a code-review checklist.
- [ ] Justify any optimizations with generated code or measurements.

**Expected outcome:** A reusable, testable and production-ready bitwise utility library.

---

## How to practise these 50 questions

For your six-year experience level, solve these as firmware engineering exercises rather than memorizing bitwise tricks.

For each question, follow this sequence:

1. **Understand the scenario:** Identify the register, field, data type or concurrency problem.
2. **Write the implementation:** Solve it in C without looking up a solution first.
3. **Trace the bits:** Show the input, mask, intermediate result and final output in hexadecimal or binary.
4. **Test edge cases:** Include zero, all bits set, the highest bit and invalid inputs wherever applicable.
5. **Review production safety:** Check integer promotions, register side effects, atomicity and portability.
6. **Explain your decisions:** Be ready to justify why your approach is safer or more suitable than an alternative.

## VS Code practice approach

- Start with ordinary, executable C programs; real hardware is not required for most questions.
- Use simulated registers and status flags for peripheral-oriented exercises.
- Compile and run each program, inspect hexadecimal output, and test edge cases.
- For concurrency and hardware-specific topics, remember that simulation demonstrates logic but cannot prove real interrupt timing or peripheral behavior.
- Keep each question in its own folder or source file and preserve the question order.

## Learning rule

Work through the questions in their fixed order, one at a time. Submit your own code first; then review correctness, edge cases, portability and production-level improvements before moving on. Do not skip ahead unless you explicitly choose to.
