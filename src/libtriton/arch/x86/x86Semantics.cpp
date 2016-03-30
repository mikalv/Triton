//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the LGPLv3 License.
*/

#include <api.hpp>
#include <cpuSize.hpp>
#include <x86Semantics.hpp>
#include <x86Specifications.hpp>



/*! \page SMT_Semantics_Supported_page SMT Semantics Supported
    \brief [**internal**] All information about the supported semantics.

\tableofcontents

\section SMT_Semantics_Supported_description Description
<hr>

Here is the instructions' list of what **Triton** can converts into \ref py_ast_page.
These semantics are based on the [Medusa's semantics](https://github.com/wisk/medusa/blob/dev/arch/x86.yaml).
Please note that our main objective is not to support all semantics right now, we are currently focusing on
the design of **Triton**'s engines. When engines will be reliable, we will write the last semantics :-).
However, feel free to add your own semantics into the [appropriate file](x86Semantics_8cpp_source.html).

\subsection SMT_Semantics_Supported_x86 x86 and x86-64 SMT semantics supported


Mnemonic                     | Extensions | Description
-----------------------------|------------|----------------------------------------------------
ADD                          |            | Add
ADC                          |            | Add with Carry
AND                          |            | Logical AND
ANDNPD                       | sse2       | Bitwise Logical AND NOT of Packed Double-Precision Floating-Point Values
ANDNPS                       | sse1       | Bitwise Logical AND NOT of Packed Single-Precision Floating-Point Values
ANDPD                        | sse2       | Bitwise Logical AND of Packed Double-Precision Floating-Point Values
ANDPS                        | sse1       | Bitwise Logical AND of Packed Single-Precision Floating-Point Values
BSF                          |            | Bit Scan Forward
BSR                          |            | Bit Scan Reverse
BSWAP                        |            | Byte Swap
CALL                         |            | Call Procedure
CBW                          |            | Convert byte (al) to word (ax).
CDQE                         |            | Convert dword (eax) to qword (rax).
CLC                          |            | Clear Carry Flag
CLD                          |            | Clear Direction Flag
CMC                          |            | Complement Carry Flag
CMOVA                        |            | Move if not below
CMOVAE                       |            | Move if not below or equal
CMOVB                        |            | Move if below
CMOVBE                       |            | Move if below or equal
CMOVE                        |            | Move if zero
CMOVG                        |            | Move if not less
CMOVGE                       |            | Move if not less or equal
CMOVL                        |            | Move if less
CMOVLE                       |            | Move if less or equal
CMOVNE                       |            | Move if not zero
CMOVNO                       |            | Move if not overflow
CMOVNP                       |            | Move if not parity
CMOVNS                       |            | Move if not sign
CMOVO                        |            | Move if overflow
CMOVP                        |            | Move if parity
CMOVS                        |            | Move if sign
CMP                          |            | Compare Two Operands
CMPXCHG                      |            | Compare and Exchange
CQO                          |            | convert qword (rax) to oword (rdx:rax)
CWDE                         |            | Convert word (ax) to dword (eax).
DEC                          |            | Decrement by 1
DIV                          |            | Unsigned Divide
IDIV                         |            | Signed Divide
IMUL                         |            | Signed Multiply
INC                          |            | Increment by 1
JA                           |            | Jump if not below (Jump if above)
JAE                          |            | Jump if not below or equal (Jump if above or equal)
JB                           |            | Jump if below
JBE                          |            | Jump if below or equal
JE                           |            | Jump if zero (Jump if equal)
JG                           |            | Jump if not less or equal (Jump if greater)
JGE                          |            | Jump if not less (Jump if not less)
JL                           |            | Jump if less
JLE                          |            | Jump if less or equal
JMP                          |            | Jump
JNO                          |            | Jump if not overflow
JNP                          |            | Jump if not parity
JNS                          |            | Jump if not sign
JNZ                          |            | Jump if not zero
JO                           |            | Jump if overflow
JP                           |            | Jump if parity
JS                           |            | Jump if sign
LEA                          |            | Load Effective Address
LEAVE                        |            | High Level Procedure Exit
MOV                          |            | Move
MOVAPD                       | sse2       | Move Aligned Packed Double-Precision Floating-Point Values
MOVAPS                       | sse1       | Move Aligned Packed Single-Precision Floating-Point Values
MOVD                         | mmx/sse2   | Move Doubleword
MOVDDUP                      | sse3       | Move One Double-FP and Duplicate
MOVDQ2Q                      | sse2       | Move Quadword from XMM to MMX Technology Register
MOVDQA                       | sse2       | Move Aligned Double Quadword
MOVDQU                       | sse2       | Move Unaligned Double Quadword
MOVHLPS                      | sse1       | Move Packed Single-Precision Floating-Point Values High to Low
MOVHPD                       | sse2       | Move High Packed Double-Precision Floating-Point Values
MOVHPS                       | sse1       | Move High Packed Single-Precision Floating-Point Values
MOVLHPS                      | sse1       | Move Packed Single-Precision Floating-Point Values Low to High
MOVLPD                       | sse2       | Move Low Packed Double-Precision Floating-Point Values
MOVLPS                       | sse1       | Move Low Packed Single-Precision Floating-Point Values
MOVMSKPD                     | sse2       | Extract Packed Double-Precision Floating-Point Sign Mask
MOVMSKPS                     | sse1       | Extract Packed Single-Precision Floating-Point Sign Mask
MOVNTDQ                      | sse2       | Store Double Quadword Using Non-Temporal Hint
MOVNTI                       | sse2       | Store Doubleword Using Non-Temporal Hint
MOVNTPD                      | sse2       | Store Packed Double-Precision Floating-Point Values Using Non-Temporal Hint
MOVNTPS                      | sse1       | Store Packed Single-Precision Floating-Point Values Using Non-Temporal Hint
MOVNTQ                       | sse1       | Store of Quadword Using Non-Temporal Hint
MOVSHDUP                     | sse3       | Move Packed Single-FP High and Duplicate
MOVSLDUP                     | sse3       | Move Packed Single-FP Low and Duplicate
MOVSX                        |            | Move with Sign-Extension
MOVZX                        |            | Move with Zero-Extend
MUL                          |            | Unsigned Multiply
NEG                          |            | Two's Complement Negation
NOP                          |            | No Operation
NOT                          |            | One's Complement Negation
OR                           |            | Logical Inclusive OR
ORPD                         | sse2       | Bitwise Logical OR of Double-Precision Floating-Point Values
ORPS                         | sse1       | Bitwise Logical OR of Single-Precision Floating-Point Values
PAND                         | mmx/sse2   | Logical AND
PANDN                        | mmx/sse2   | Logical AND NOT
PCMPEQB                      | mmx/sse2   | Compare Packed Data for Equal (bytes)
PCMPEQD                      | mmx/sse2   | Compare Packed Data for Equal (dwords)
PCMPEQW                      | mmx/sse2   | Compare Packed Data for Equal (words)
PMOVMSKB                     | sse1       | Move Byte Mask
POP                          |            | Pop a Value from the Stack
POR                          |            | Bitwise Logical OR
PUSH                         |            | Push a Value onto the Stack
PXOR                         |            | Logical Exclusive OR
RCL                          |            | Rotate Left with Carry
RCR                          |            | Rotate Right with Carry
RET                          |            | Return from Procedure
ROL                          |            | Rotate Left
ROR                          |            | Rotate Right
SAL                          |            | Shift Left
SAR                          |            | Shift Right Signed
SBB                          |            | Integer Subtraction with Borrow
SETA                         |            | Set byte if above
SETAE                        |            | Set byte if above or equal
SETB                         |            | Set byte if below
SETBE                        |            | Set byte if below or equal
SETE                         |            | Set byte if zero
SETG                         |            | Set byte if greater
SETGE                        |            | Set byte if greater or equal
SETL                         |            | Set byte if less
SETLE                        |            | Set byte if less or equal
SETNE                        |            | Set byte if not zero
SETNO                        |            | Set byte if not overflow
SETNP                        |            | Set byte if not parity
SETNS                        |            | Set byte if not sign
SETO                         |            | Set byte if overflow
SETP                         |            | Set byte if parity
SETS                         |            | Set byte if sign
SHL                          |            | Shift Left
SHR                          |            | Shift Right Unsigned
STC                          |            | Set Carry Flag
STD                          |            | Set Direction Flag
SUB                          |            | Subtract
TEST                         |            | Logical Compare
VMOVDQA                      | avx2       | VEX Move aligned packed integer values
XADD                         |            | Exchange and Add
XCHG                         |            | Exchange Register/Memory with Register
XOR                          |            | Logical Exclusive OR
XORPD                        | sse2       | Bitwise Logical XOR for Double-Precision Floating-Point Values
XORPS                        | sse1       | Bitwise Logical XOR for Single-Precision Floating-Point Values

*/



namespace triton {
  namespace arch {
    namespace x86 {
      namespace semantics {


        void build(triton::arch::Instruction& inst) {
          switch (inst.getType()) {
            case ID_INS_ADC:            triton::arch::x86::semantics::adc_s(inst);        break;
            case ID_INS_ADD:            triton::arch::x86::semantics::add_s(inst);        break;
            case ID_INS_AND:            triton::arch::x86::semantics::and_s(inst);        break;
            case ID_INS_ANDNPD:         triton::arch::x86::semantics::andnpd_s(inst);     break;
            case ID_INS_ANDNPS:         triton::arch::x86::semantics::andnps_s(inst);     break;
            case ID_INS_ANDPD:          triton::arch::x86::semantics::andpd_s(inst);      break;
            case ID_INS_ANDPS:          triton::arch::x86::semantics::andps_s(inst);      break;
            case ID_INS_BSF:            triton::arch::x86::semantics::bsf_s(inst);        break;
            case ID_INS_BSR:            triton::arch::x86::semantics::bsr_s(inst);        break;
            case ID_INS_BSWAP:          triton::arch::x86::semantics::bswap_s(inst);      break;
            case ID_INS_CALL:           triton::arch::x86::semantics::call_s(inst);       break;
            case ID_INS_CBW:            triton::arch::x86::semantics::cbw_s(inst);        break;
            case ID_INS_CDQE:           triton::arch::x86::semantics::cdqe_s(inst);       break;
            case ID_INS_CLC:            triton::arch::x86::semantics::clc_s(inst);        break;
            case ID_INS_CLD:            triton::arch::x86::semantics::cld_s(inst);        break;
            case ID_INS_CMC:            triton::arch::x86::semantics::cmc_s(inst);        break;
            case ID_INS_CMOVA:          triton::arch::x86::semantics::cmova_s(inst);      break;
            case ID_INS_CMOVAE:         triton::arch::x86::semantics::cmovae_s(inst);     break;
            case ID_INS_CMOVB:          triton::arch::x86::semantics::cmovb_s(inst);      break;
            case ID_INS_CMOVBE:         triton::arch::x86::semantics::cmovbe_s(inst);     break;
            case ID_INS_CMOVE:          triton::arch::x86::semantics::cmove_s(inst);      break;
            case ID_INS_CMOVG:          triton::arch::x86::semantics::cmovg_s(inst);      break;
            case ID_INS_CMOVGE:         triton::arch::x86::semantics::cmovge_s(inst);     break;
            case ID_INS_CMOVL:          triton::arch::x86::semantics::cmovl_s(inst);      break;
            case ID_INS_CMOVLE:         triton::arch::x86::semantics::cmovle_s(inst);     break;
            case ID_INS_CMOVNE:         triton::arch::x86::semantics::cmovne_s(inst);     break;
            case ID_INS_CMOVNO:         triton::arch::x86::semantics::cmovno_s(inst);     break;
            case ID_INS_CMOVNP:         triton::arch::x86::semantics::cmovnp_s(inst);     break;
            case ID_INS_CMOVNS:         triton::arch::x86::semantics::cmovns_s(inst);     break;
            case ID_INS_CMOVO:          triton::arch::x86::semantics::cmovo_s(inst);      break;
            case ID_INS_CMOVP:          triton::arch::x86::semantics::cmovp_s(inst);      break;
            case ID_INS_CMOVS:          triton::arch::x86::semantics::cmovs_s(inst);      break;
            case ID_INS_CMP:            triton::arch::x86::semantics::cmp_s(inst);        break;
            case ID_INS_CMPXCHG:        triton::arch::x86::semantics::cmpxchg_s(inst);    break;
            case ID_INS_CQO:            triton::arch::x86::semantics::cqo_s(inst);        break;
            case ID_INS_CWDE:           triton::arch::x86::semantics::cwde_s(inst);       break;
            case ID_INS_DEC:            triton::arch::x86::semantics::dec_s(inst);        break;
            case ID_INS_DIV:            triton::arch::x86::semantics::div_s(inst);        break;
            case ID_INS_IDIV:           triton::arch::x86::semantics::idiv_s(inst);       break;
            case ID_INS_IMUL:           triton::arch::x86::semantics::imul_s(inst);       break;
            case ID_INS_INC:            triton::arch::x86::semantics::inc_s(inst);        break;
            case ID_INS_JA:             triton::arch::x86::semantics::ja_s(inst);         break;
            case ID_INS_JAE:            triton::arch::x86::semantics::jae_s(inst);        break;
            case ID_INS_JB:             triton::arch::x86::semantics::jb_s(inst);         break;
            case ID_INS_JBE:            triton::arch::x86::semantics::jbe_s(inst);        break;
            case ID_INS_JE:             triton::arch::x86::semantics::je_s(inst);         break;
            case ID_INS_JG:             triton::arch::x86::semantics::jg_s(inst);         break;
            case ID_INS_JGE:            triton::arch::x86::semantics::jge_s(inst);        break;
            case ID_INS_JL:             triton::arch::x86::semantics::jl_s(inst);         break;
            case ID_INS_JLE:            triton::arch::x86::semantics::jle_s(inst);        break;
            case ID_INS_JMP:            triton::arch::x86::semantics::jmp_s(inst);        break;
            case ID_INS_JNE:            triton::arch::x86::semantics::jne_s(inst);        break;
            case ID_INS_JNO:            triton::arch::x86::semantics::jno_s(inst);        break;
            case ID_INS_JNP:            triton::arch::x86::semantics::jnp_s(inst);        break;
            case ID_INS_JNS:            triton::arch::x86::semantics::jns_s(inst);        break;
            case ID_INS_JO:             triton::arch::x86::semantics::jo_s(inst);         break;
            case ID_INS_JP:             triton::arch::x86::semantics::jp_s(inst);         break;
            case ID_INS_JS:             triton::arch::x86::semantics::js_s(inst);         break;
            case ID_INS_LEA:            triton::arch::x86::semantics::lea_s(inst);        break;
            case ID_INS_LEAVE:          triton::arch::x86::semantics::leave_s(inst);      break;
            case ID_INS_MOV:            triton::arch::x86::semantics::mov_s(inst);        break;
            case ID_INS_MOVABS:         triton::arch::x86::semantics::movabs_s(inst);     break;
            case ID_INS_MOVAPD:         triton::arch::x86::semantics::movapd_s(inst);     break;
            case ID_INS_MOVAPS:         triton::arch::x86::semantics::movaps_s(inst);     break;
            case ID_INS_MOVD:           triton::arch::x86::semantics::movd_s(inst);       break;
            case ID_INS_MOVDDUP:        triton::arch::x86::semantics::movddup_s(inst);    break;
            case ID_INS_MOVDQ2Q:        triton::arch::x86::semantics::movdq2q_s(inst);    break;
            case ID_INS_MOVDQA:         triton::arch::x86::semantics::movdqa_s(inst);     break;
            case ID_INS_MOVDQU:         triton::arch::x86::semantics::movdqu_s(inst);     break;
            case ID_INS_MOVHLPS:        triton::arch::x86::semantics::movhlps_s(inst);    break;
            case ID_INS_MOVHPD:         triton::arch::x86::semantics::movhpd_s(inst);     break;
            case ID_INS_MOVHPS:         triton::arch::x86::semantics::movhps_s(inst);     break;
            case ID_INS_MOVLHPS:        triton::arch::x86::semantics::movlhps_s(inst);    break;
            case ID_INS_MOVLPD:         triton::arch::x86::semantics::movlpd_s(inst);     break;
            case ID_INS_MOVLPS:         triton::arch::x86::semantics::movlps_s(inst);     break;
            case ID_INS_MOVMSKPD:       triton::arch::x86::semantics::movmskpd_s(inst);   break;
            case ID_INS_MOVMSKPS:       triton::arch::x86::semantics::movmskps_s(inst);   break;
            case ID_INS_MOVNTDQ:        triton::arch::x86::semantics::movntdq_s(inst);    break;
            case ID_INS_MOVNTI:         triton::arch::x86::semantics::movnti_s(inst);     break;
            case ID_INS_MOVNTPD:        triton::arch::x86::semantics::movntpd_s(inst);    break;
            case ID_INS_MOVNTPS:        triton::arch::x86::semantics::movntps_s(inst);    break;
            case ID_INS_MOVNTQ:         triton::arch::x86::semantics::movntq_s(inst);     break;
            case ID_INS_MOVSHDUP:       triton::arch::x86::semantics::movshdup_s(inst);   break;
            case ID_INS_MOVSLDUP:       triton::arch::x86::semantics::movsldup_s(inst);   break;
            case ID_INS_MOVSX:          triton::arch::x86::semantics::movsx_s(inst);      break;
            case ID_INS_MOVSXD:         triton::arch::x86::semantics::movsxd_s(inst);     break;
            case ID_INS_MOVZX:          triton::arch::x86::semantics::movzx_s(inst);      break;
            case ID_INS_MUL:            triton::arch::x86::semantics::mul_s(inst);        break;
            case ID_INS_NEG:            triton::arch::x86::semantics::neg_s(inst);        break;
            case ID_INS_NOP:            triton::arch::x86::semantics::nop_s(inst);        break;
            case ID_INS_NOT:            triton::arch::x86::semantics::not_s(inst);        break;
            case ID_INS_OR:             triton::arch::x86::semantics::or_s(inst);         break;
            case ID_INS_ORPD:           triton::arch::x86::semantics::orpd_s(inst);       break;
            case ID_INS_ORPS:           triton::arch::x86::semantics::orps_s(inst);       break;
            case ID_INS_PAND:           triton::arch::x86::semantics::pand_s(inst);       break;
            case ID_INS_PANDN:          triton::arch::x86::semantics::pandn_s(inst);      break;
            case ID_INS_PCMPEQB:        triton::arch::x86::semantics::pcmpeqb_s(inst);    break;
            case ID_INS_PCMPEQD:        triton::arch::x86::semantics::pcmpeqd_s(inst);    break;
            case ID_INS_PCMPEQW:        triton::arch::x86::semantics::pcmpeqw_s(inst);    break;
            case ID_INS_PMOVMSKB:       triton::arch::x86::semantics::pmovmskb_s(inst);   break;
            case ID_INS_POP:            triton::arch::x86::semantics::pop_s(inst);        break;
            case ID_INS_POR:            triton::arch::x86::semantics::por_s(inst);        break;
            case ID_INS_PUSH:           triton::arch::x86::semantics::push_s(inst);       break;
            case ID_INS_PXOR:           triton::arch::x86::semantics::pxor_s(inst);       break;
            case ID_INS_RCL:            triton::arch::x86::semantics::rcl_s(inst);        break;
            case ID_INS_RCR:            triton::arch::x86::semantics::rcr_s(inst);        break;
            case ID_INS_RET:            triton::arch::x86::semantics::ret_s(inst);        break;
            case ID_INS_ROL:            triton::arch::x86::semantics::rol_s(inst);        break;
            case ID_INS_ROR:            triton::arch::x86::semantics::ror_s(inst);        break;
            case ID_INS_SAL:            triton::arch::x86::semantics::shl_s(inst);        break;
            case ID_INS_SAR:            triton::arch::x86::semantics::sar_s(inst);        break;
            case ID_INS_SBB:            triton::arch::x86::semantics::sbb_s(inst);        break;
            case ID_INS_SETA:           triton::arch::x86::semantics::seta_s(inst);       break;
            case ID_INS_SETAE:          triton::arch::x86::semantics::setae_s(inst);      break;
            case ID_INS_SETB:           triton::arch::x86::semantics::setb_s(inst);       break;
            case ID_INS_SETBE:          triton::arch::x86::semantics::setbe_s(inst);      break;
            case ID_INS_SETE:           triton::arch::x86::semantics::sete_s(inst);       break;
            case ID_INS_SETG:           triton::arch::x86::semantics::setg_s(inst);       break;
            case ID_INS_SETGE:          triton::arch::x86::semantics::setge_s(inst);      break;
            case ID_INS_SETL:           triton::arch::x86::semantics::setl_s(inst);       break;
            case ID_INS_SETLE:          triton::arch::x86::semantics::setle_s(inst);      break;
            case ID_INS_SETNE:          triton::arch::x86::semantics::setne_s(inst);      break;
            case ID_INS_SETNO:          triton::arch::x86::semantics::setno_s(inst);      break;
            case ID_INS_SETNP:          triton::arch::x86::semantics::setnp_s(inst);      break;
            case ID_INS_SETNS:          triton::arch::x86::semantics::setns_s(inst);      break;
            case ID_INS_SETO:           triton::arch::x86::semantics::seto_s(inst);       break;
            case ID_INS_SETP:           triton::arch::x86::semantics::setp_s(inst);       break;
            case ID_INS_SETS:           triton::arch::x86::semantics::sets_s(inst);       break;
            case ID_INS_SHL:            triton::arch::x86::semantics::shl_s(inst);        break;
            case ID_INS_SHR:            triton::arch::x86::semantics::shr_s(inst);        break;
            case ID_INS_STC:            triton::arch::x86::semantics::stc_s(inst);        break;
            case ID_INS_STD:            triton::arch::x86::semantics::std_s(inst);        break;
            case ID_INS_SUB:            triton::arch::x86::semantics::sub_s(inst);        break;
            case ID_INS_TEST:           triton::arch::x86::semantics::test_s(inst);       break;
            case ID_INS_VMOVDQA:        triton::arch::x86::semantics::vmovdqa_s(inst);    break;
            case ID_INS_XADD:           triton::arch::x86::semantics::xadd_s(inst);       break;
            case ID_INS_XCHG:           triton::arch::x86::semantics::xchg_s(inst);       break;
            case ID_INS_XOR:            triton::arch::x86::semantics::xor_s(inst);        break;
            case ID_INS_XORPD:          triton::arch::x86::semantics::xorpd_s(inst);      break;
            case ID_INS_XORPS:          triton::arch::x86::semantics::xorps_s(inst);      break;
          }
        }


        void alignAddStack_s(triton::arch::Instruction& inst, triton::uint32 delta) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_SP.getParent());

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::bv(delta, dst.getBitSize());

          /* Create the semantics */
          auto node = triton::ast::bvadd(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "Stack alignment");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, dst);
        }


        void alignSubStack_s(triton::arch::Instruction& inst, triton::uint32 delta) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_SP.getParent());

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::bv(delta, dst.getBitSize());

          /* Create the semantics */
          auto node = triton::ast::bvsub(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "Stack alignment");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, dst);
        }


        void clearFlag_s(triton::arch::Instruction& inst, triton::arch::RegisterOperand& flag, std::string comment) {
          /* Create the semantics */
          auto node = triton::ast::bv(0, 1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, flag, comment);

          /* Spread taint */
          expr->isTainted = triton::api.setTaintRegister(flag, triton::engines::taint::UNTAINTED);
        }


        void setFlag_s(triton::arch::Instruction& inst, triton::arch::RegisterOperand& flag, std::string comment) {
          /* Create the semantics */
          auto node = triton::ast::bv(1, 1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, flag, comment);

          /* Spread taint */
          expr->isTainted = triton::api.setTaintRegister(flag, triton::engines::taint::UNTAINTED);
        }


        void controlFlow_s(triton::arch::Instruction& inst) {
          /* Create the semantics */
          auto node = triton::ast::bv(inst.getAddress() + inst.getOpcodesSize(), triton::api.cpuRegisterBitSize());

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicRegisterExpression(inst, node, TRITON_X86_REG_PC, "Program Counter");

          /* Spread taint */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_PC, triton::engines::taint::UNTAINTED);
        }


        void af_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * af = 0x10 == (0x10 & (regDst ^ op1 ^ op2))
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bv(0x10, bvSize),
                          triton::ast::bvand(
                            triton::ast::bv(0x10, bvSize),
                            triton::ast::bvxor(
                              triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                              triton::ast::bvxor(op1, op2)
                            )
                          )
                        ),
                        triton::ast::bv(1, 1),
                        triton::ast::bv(0, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_AF, "Adjust flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_AF, parent->isTainted);
        }


        void afNeg_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * af = 0x10 == (0x10 & (op1 ^ regDst))
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bv(0x10, bvSize),
                          triton::ast::bvand(
                            triton::ast::bv(0x10, bvSize),
                            triton::ast::bvxor(
                              op1,
                              triton::ast::extract(high, low, triton::ast::reference(parent->getId()))
                            )
                          )
                        ),
                        triton::ast::bv(1, 1),
                        triton::ast::bv(0, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_AF, "Adjust flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_AF, parent->isTainted);
        }


        void cfAdd_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * cf = extract(bvSize, bvSize, ((op0 & op1) ^ ((op0 ^ op1 ^ parent) & (op0 ^ op1))));
           */
          auto node = triton::ast::extract(high, high,
                        triton::ast::bvxor(
                          triton::ast::bvand(op1, op2),
                          triton::ast::bvand(
                            triton::ast::bvxor(
                              triton::ast::bvxor(op1, op2),
                              triton::ast::extract(high, low, triton::ast::reference(parent->getId()))
                            ),
                          triton::ast::bvxor(op1, op2))
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfImul_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* res, bool vol) {
          /*
           * Create the semantic.
           * cf = 0 if sx(dst) == node else 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::sx(dst.getBitSize(), op1),
                          res
                        ),
                        triton::ast::bv(0, 1),
                        triton::ast::bv(1, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfMul_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, bool vol) {
          auto bvSize = dst.getBitSize();

          /*
           * Create the semantic.
           * cf = 0 if op1 == 0 else 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          op1,
                          triton::ast::bv(0, bvSize)
                        ),
                        triton::ast::bv(0, 1),
                        triton::ast::bv(1, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfNeg_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, bool vol) {
          auto bvSize = dst.getBitSize();

          /*
           * Create the semantic.
           * cf = 0 if op1 == 0 else 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          op1,
                          triton::ast::bv(0, bvSize)
                        ),
                        triton::ast::bv(0, 1),
                        triton::ast::bv(1, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfRcl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * cf = high(res & 1) if op2 != 0 else undefined
           * As the second operand can't be symbolized, there is
           * no symbolic expression available. So, we must use the
           * concretization of the op2.
           */
          triton::ast::AbstractNode* node;
          if (op2->getKind() != triton::ast::DECIMAL_NODE)
            throw std::runtime_error("triton::arch::x86::semantics::cfRcl_s(): op2 must be a DecimalNode node.");

          if (reinterpret_cast<triton::ast::DecimalNode*>(op2)->getValue() != 0)
            node = triton::ast::extract(high, high, triton::ast::reference(parent->getId()));
          else
            node = triton::api.buildSymbolicOperand(cf);

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfRol_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto low = vol ? 0 : dst.getAbstractLow();
          auto cf  = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * cf = (res & 1) if op2 != 0 else undefined
           * As the second operand can't be symbolized, there is
           * no symbolic expression available. So, we must use the
           * concretization of the op2.
           */
          triton::ast::AbstractNode* node;
          if (op2->getKind() != triton::ast::DECIMAL_NODE)
            throw std::runtime_error("triton::arch::x86::semantics::cfRol_s(): op2 must be a DecimalNode node.");

          if (reinterpret_cast<triton::ast::DecimalNode*>(op2)->getValue() != 0)
            node = triton::ast::extract(low, low, triton::ast::reference(parent->getId()));
          else
            node = triton::api.buildSymbolicOperand(cf);

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfRor_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * cf = (res >> bvSize - 1) & 1 if op2 != 0 else undefined
           * As the second operand can't be symbolized, there is
           * no symbolic expression available. So, we must use the
           * concretization of the op2.
           */
          if (op2->getKind() != triton::ast::DECIMAL_NODE)
            throw std::runtime_error("triton::arch::x86::semantics::cfRor_s(): op2 must be a DecimalNode node.");

          triton::ast::AbstractNode* node;
          if (reinterpret_cast<triton::ast::DecimalNode*>(op2)->getValue() != 0) {
            node = triton::ast::extract(0, 0,
              triton::ast::bvlshr(
                triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                triton::ast::bvsub(
                  triton::ast::bv(bvSize, bvSize),
                  triton::ast::bv(1, bvSize)
                )
              )
            );
          }
          else {
            node = triton::api.buildSymbolicOperand(cf);
          }

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfSar_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * if op2 != 0:
           *   if op2 > bvSize:
           *     cf.id = ((op1 >> (bvSize - 1)) & 1)
           *   else:
           *     cf.id = ((op1 >> (op2 - 1)) & 1)
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::api.buildSymbolicOperand(cf),
                        triton::ast::ite(
                          triton::ast::bvugt(op2, triton::ast::bv(bvSize, bvSize)),
                          triton::ast::extract(0, 0, triton::ast::bvlshr(op1, triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(1, bvSize)))),
                          triton::ast::extract(0, 0, triton::ast::bvlshr(op1, triton::ast::bvsub(op2, triton::ast::bv(1, bvSize))))
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfShl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * cf = (op1 >> ((bvSize - (op2 & bvSize-1)) & 1) if op2 != 0
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::api.buildSymbolicOperand(cf),
                        triton::ast::extract(0, 0,
                          triton::ast::bvlshr(
                            op1,
                            triton::ast::bvsub(
                              triton::ast::bv(bvSize, bvSize),
                              triton::ast::bvand(op2, triton::ast::bv(bvSize-1, bvSize))
                            )
                          )
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfShr_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /*
           * Create the semantic.
           * cf = ((op1 >> ((op2 & bvSize-1) - 1)) & 1) if op2 != 0
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::api.buildSymbolicOperand(cf),
                        triton::ast::extract(0, 0,
                          triton::ast::bvlshr(
                            op1,
                            triton::ast::bvsub(
                              triton::ast::bvand(op2, triton::ast::bv(bvSize-1, bvSize)),
                              triton::ast::bv(1, bvSize))
                          )
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void cfSub_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * cf = extract(bvSize, bvSize (((op1 ^ op2 ^ res) ^ ((op1 ^ res) & (op1 ^ op2)))))
           */
          auto node = triton::ast::extract(high, high,
                        triton::ast::bvxor(
                          triton::ast::bvxor(op1, triton::ast::bvxor(op2, triton::ast::extract(high, low, triton::ast::reference(parent->getId())))),
                          triton::ast::bvand(
                            triton::ast::bvxor(op1, triton::ast::extract(high, low, triton::ast::reference(parent->getId()))),
                            triton::ast::bvxor(op1, op2)
                          )
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_CF, "Carry flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_CF, parent->isTainted);
        }


        void ofAdd_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * of = high:bool((op1 ^ ~op2) & (op1 ^ regDst))
           */
          auto node = triton::ast::extract(high, high,
                        triton::ast::bvand(
                          triton::ast::bvxor(op1, triton::ast::bvnot(op2)),
                          triton::ast::bvxor(op1, triton::ast::extract(high, low, triton::ast::reference(parent->getId())))
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofImul_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* res, bool vol) {
          /*
           * Create the semantic.
           * of = 0 if sx(dst) == node else 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::sx(dst.getBitSize(), op1),
                          res
                        ),
                        triton::ast::bv(0, 1),
                        triton::ast::bv(1, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofMul_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, bool vol) {
          auto bvSize = dst.getBitSize();

          /*
           * Create the semantic.
           * of = 0 if up == 0 else 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          op1,
                          triton::ast::bv(0, bvSize)
                        ),
                        triton::ast::bv(0, 1),
                        triton::ast::bv(1, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofNeg_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * of = (res & op1) >> (bvSize - 1) & 1
           */
          auto node = triton::ast::extract(0, 0,
                        triton::ast::bvshl(
                          triton::ast::bvand(triton::ast::extract(high, low, triton::ast::reference(parent->getId())), op1),
                          triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(1, bvSize))
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofRol_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto cf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));
          auto of     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_OF));

          /*
           * Create the semantic.
           * of = ((cf ^ (res >> (bvsize - 1))) & 1) if op2 == 1 else undefined
           * As the second operand can't be symbolized, there is
           * no symbolic expression available. So, we must use the
           * concretization of the op2.
           */
          if (op2->getKind() != triton::ast::DECIMAL_NODE)
            throw std::runtime_error("triton::arch::x86::semantics::ofRol_s(): op2 must be a DecimalNode node.");

          triton::ast::AbstractNode* node;
          if (reinterpret_cast<triton::ast::DecimalNode*>(op2)->getValue() == 1) {
            node = triton::ast::extract(0, 0,
                      triton::ast::bvxor(
                        triton::ast::zx(bvSize-1, triton::api.buildSymbolicOperand(cf)),
                        triton::ast::bvshl(
                          triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                          triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(1, bvSize))
                        )
                      )
                    );
          }
          else {
            node = triton::api.buildSymbolicOperand(of);
          }

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofRor_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto of     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_OF));

          /*
           * Create the semantic.
           * of = (((res >> (bvSize - 1)) ^ (res >> (bvSize - 2))) & 1) if op2 == 1 else undefined
           * As the second operand can't be symbolized, there is
           * no symbolic expression available. So, we must use the
           * concretization of the op2.
           */
          if (op2->getKind() != triton::ast::DECIMAL_NODE)
            throw std::runtime_error("triton::arch::x86::semantics::ofRor_s(): op2 must be a DecimalNode node.");

          triton::ast::AbstractNode* node;
          if (reinterpret_cast<triton::ast::DecimalNode *>(op2)->getValue() == 1) {
            node = triton::ast::extract(0, 0,
                     triton::ast::bvxor(
                       triton::ast::bvshl(
                         triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                         triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(1, bvSize))
                       ),
                       triton::ast::bvshl(
                         triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                         triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(2, bvSize))
                       )
                     )
                   );
          }
          else {
            node = triton::api.buildSymbolicOperand(of);
          }

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofSar_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto of     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_OF));

          /*
           * Create the semantic.
           * of = 0 if (op2 & bvSize-1) == 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bvand(op2, triton::ast::bv(bvSize-1, bvSize)),
                          triton::ast::bv(1, bvSize)),
                        triton::ast::bv(0, 1),
                        triton::api.buildSymbolicOperand(of)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofShl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto of     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_OF));

          /*
           * Create the semantic.
           * of = bit_cast((op1 >> (bvSize - 1)) ^ (op1 >> (bvSize - 2)), int1(1)); if (op2 & bvSize-1) == 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bvand(op2, triton::ast::bv(bvSize-1, bvSize)),
                          triton::ast::bv(1, bvSize)),
                        triton::ast::extract(0, 0,
                          triton::ast::bvxor(
                            triton::ast::bvlshr(op1, triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(1, bvSize))),
                            triton::ast::bvlshr(op1, triton::ast::bvsub(triton::ast::bv(bvSize, bvSize), triton::ast::bv(2, bvSize)))
                          )
                        ),
                        triton::api.buildSymbolicOperand(of)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofShr_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto of     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_OF));

          /*
           * Create the semantic.
           * of = (op1 >> (bvSize - 1) & 1) if (op2 & bvSize-1) == 1
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bvand(op2, triton::ast::bv(bvSize-1, bvSize)),
                          triton::ast::bv(1, bvSize)),
                        triton::ast::extract(high, high, op1),
                        triton::api.buildSymbolicOperand(of)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void ofSub_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op1, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * of = high:bool((op1 ^ op2) & (op1 ^ regDst))
           */
          auto node = triton::ast::extract(high, high,
                        triton::ast::bvand(
                          triton::ast::bvxor(op1, op2),
                          triton::ast::bvxor(op1, triton::ast::extract(high, low, triton::ast::reference(parent->getId())))
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_OF, "Overflow flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_OF, parent->isTainted);
        }


        void pf_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, bool vol) {
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? BYTE_SIZE_BIT-1 : !low ? BYTE_SIZE_BIT-1 : WORD_SIZE_BIT-1;

          /*
           * Create the semantics.
           *
           * pf is set to one if there is an even number of bit set to 1 in the least
           * significant byte of the result.
           */
          auto node = triton::ast::bv(1, 1);
          for (triton::uint32 counter = 0; counter <= BYTE_SIZE_BIT-1; counter++) {
            node = triton::ast::bvxor(
                     node,
                     triton::ast::extract(0, 0,
                       triton::ast::bvlshr(
                         triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                         triton::ast::bv(counter, BYTE_SIZE_BIT)
                       )
                    )
                  );
          }

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_PF, "Parity flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_PF, parent->isTainted);
        }


        void pfShl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? BYTE_SIZE_BIT-1 : !low ? BYTE_SIZE_BIT-1 : WORD_SIZE_BIT-1;
          auto pf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_PF));

          /*
           * Create the semantics.
           * pf if op2 != 0
           */
          auto node1 = triton::ast::bv(1, 1);
          for (triton::uint32 counter = 0; counter <= BYTE_SIZE_BIT-1; counter++) {
            node1 = triton::ast::bvxor(
                     node1,
                     triton::ast::extract(0, 0,
                       triton::ast::bvlshr(
                         triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                         triton::ast::bv(counter, BYTE_SIZE_BIT)
                       )
                    )
                  );
          }

          auto node2 = triton::ast::ite(
                         triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                         triton::api.buildSymbolicOperand(pf),
                         node1
                       );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node2, TRITON_X86_REG_PF, "Parity flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_PF, parent->isTainted);
        }


        void sf_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, bool vol) {
          auto bvSize = dst.getBitSize();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * sf = high:bool(regDst)
           */
          auto node = triton::ast::extract(high, high, triton::ast::reference(parent->getId()));

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_SF, "Sign flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_SF, parent->isTainted);
        }


        void sfShl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto sf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_SF));

          /*
           * Create the semantic.
           * sf if op2 != 0
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::api.buildSymbolicOperand(sf),
                        triton::ast::extract(high, high, triton::ast::reference(parent->getId()))
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_SF, "Sign flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_SF, parent->isTainted);
        }


        void zf_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();

          /*
           * Create the semantic.
           * zf = 0 == regDst
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                          triton::ast::bv(0, bvSize)
                        ),
                        triton::ast::bv(1, 1),
                        triton::ast::bv(0, 1)
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_ZF, "Zero flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_ZF, parent->isTainted);
        }


        void zfBsf_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& src, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = src.getBitSize();

          /*
           * Create the semantic.
           * zf = 1 if op2 == 0 else 0
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::ast::bvtrue(),
                        triton::ast::bvfalse()
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_ZF, "Zero flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_ZF, parent->isTainted);
        }


        void zfShl_s(triton::arch::Instruction& inst, triton::engines::symbolic::SymbolicExpression* parent, triton::arch::OperandWrapper& dst, triton::ast::AbstractNode* op2, bool vol) {
          auto bvSize = dst.getBitSize();
          auto low    = vol ? 0 : dst.getAbstractLow();
          auto high   = vol ? bvSize-1 : dst.getAbstractHigh();
          auto zf     = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_ZF));

          /*
           * Create the semantic.
           * zf if op2 != 0
           */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bv(0, bvSize)),
                        triton::api.buildSymbolicOperand(zf),
                        triton::ast::ite(
                          triton::ast::equal(
                            triton::ast::extract(high, low, triton::ast::reference(parent->getId())),
                            triton::ast::bv(0, bvSize)
                          ),
                          triton::ast::bv(1, 1),
                          triton::ast::bv(0, 1)
                        )
                      );

          /* Create the symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, TRITON_X86_REG_ZF, "Zero flag");

          /* Spread the taint from the parent to the child */
          expr->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_ZF, parent->isTainted);
        }


        void adc_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(cf);

          /* Create the semantics */
          auto node = triton::ast::bvadd(triton::ast::bvadd(op1, op2), triton::ast::zx(dst.getBitSize()-1, op3));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ADC operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);
          expr->isTainted = triton::api.taintUnion(dst, cf);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::cfAdd_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofAdd_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void add_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvadd(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ADD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::cfAdd_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofAdd_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void and_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "AND operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_CF, "Clears carry flag");
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_OF, "Clears overflow flag");
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void andnpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(triton::ast::bvnot(op1), op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ANDNPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void andnps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(triton::ast::bvnot(op1), op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ANDNPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void andpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ANDPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void andps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ANDPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void bsf_s(triton::arch::Instruction& inst) {
          auto dst     = inst.operands[0];
          auto src     = inst.operands[1];
          auto bvSize1 = dst.getBitSize();
          auto bvSize2 = src.getBitSize();

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          triton::ast::AbstractNode* node = nullptr;
          switch (src.getSize()) {
            case BYTE_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSF only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))
                     );
              break;
            case WORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSF only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))
                     );
              break;
            case DWORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSF only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(16, 16, op2), triton::ast::bvtrue()), triton::ast::bv(16, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(17, 17, op2), triton::ast::bvtrue()), triton::ast::bv(17, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(18, 18, op2), triton::ast::bvtrue()), triton::ast::bv(18, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(19, 19, op2), triton::ast::bvtrue()), triton::ast::bv(19, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(20, 20, op2), triton::ast::bvtrue()), triton::ast::bv(20, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(21, 21, op2), triton::ast::bvtrue()), triton::ast::bv(21, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(22, 22, op2), triton::ast::bvtrue()), triton::ast::bv(22, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(23, 23, op2), triton::ast::bvtrue()), triton::ast::bv(23, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(24, 24, op2), triton::ast::bvtrue()), triton::ast::bv(24, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(25, 25, op2), triton::ast::bvtrue()), triton::ast::bv(25, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(26, 26, op2), triton::ast::bvtrue()), triton::ast::bv(26, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(27, 27, op2), triton::ast::bvtrue()), triton::ast::bv(27, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(28, 28, op2), triton::ast::bvtrue()), triton::ast::bv(28, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(29, 29, op2), triton::ast::bvtrue()), triton::ast::bv(29, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(30, 30, op2), triton::ast::bvtrue()), triton::ast::bv(30, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(31, 31, op2), triton::ast::bvtrue()), triton::ast::bv(31, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))))))))))))))))))
                     );
              break;
            case QWORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSF only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(16, 16, op2), triton::ast::bvtrue()), triton::ast::bv(16, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(17, 17, op2), triton::ast::bvtrue()), triton::ast::bv(17, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(18, 18, op2), triton::ast::bvtrue()), triton::ast::bv(18, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(19, 19, op2), triton::ast::bvtrue()), triton::ast::bv(19, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(20, 20, op2), triton::ast::bvtrue()), triton::ast::bv(20, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(21, 21, op2), triton::ast::bvtrue()), triton::ast::bv(21, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(22, 22, op2), triton::ast::bvtrue()), triton::ast::bv(22, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(23, 23, op2), triton::ast::bvtrue()), triton::ast::bv(23, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(24, 24, op2), triton::ast::bvtrue()), triton::ast::bv(24, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(25, 25, op2), triton::ast::bvtrue()), triton::ast::bv(25, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(26, 26, op2), triton::ast::bvtrue()), triton::ast::bv(26, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(27, 27, op2), triton::ast::bvtrue()), triton::ast::bv(27, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(28, 28, op2), triton::ast::bvtrue()), triton::ast::bv(28, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(29, 29, op2), triton::ast::bvtrue()), triton::ast::bv(29, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(30, 30, op2), triton::ast::bvtrue()), triton::ast::bv(30, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(31, 31, op2), triton::ast::bvtrue()), triton::ast::bv(31, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(32, 32, op2), triton::ast::bvtrue()), triton::ast::bv(32, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(33, 33, op2), triton::ast::bvtrue()), triton::ast::bv(33, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(34, 34, op2), triton::ast::bvtrue()), triton::ast::bv(34, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(35, 35, op2), triton::ast::bvtrue()), triton::ast::bv(35, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(36, 36, op2), triton::ast::bvtrue()), triton::ast::bv(36, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(37, 37, op2), triton::ast::bvtrue()), triton::ast::bv(37, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(38, 38, op2), triton::ast::bvtrue()), triton::ast::bv(38, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(39, 39, op2), triton::ast::bvtrue()), triton::ast::bv(39, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(40, 40, op2), triton::ast::bvtrue()), triton::ast::bv(40, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(41, 41, op2), triton::ast::bvtrue()), triton::ast::bv(41, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(42, 42, op2), triton::ast::bvtrue()), triton::ast::bv(42, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(43, 43, op2), triton::ast::bvtrue()), triton::ast::bv(43, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(44, 44, op2), triton::ast::bvtrue()), triton::ast::bv(44, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(45, 45, op2), triton::ast::bvtrue()), triton::ast::bv(45, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(46, 46, op2), triton::ast::bvtrue()), triton::ast::bv(46, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(47, 47, op2), triton::ast::bvtrue()), triton::ast::bv(47, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(48, 48, op2), triton::ast::bvtrue()), triton::ast::bv(48, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(49, 49, op2), triton::ast::bvtrue()), triton::ast::bv(49, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(50, 50, op2), triton::ast::bvtrue()), triton::ast::bv(50, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(51, 51, op2), triton::ast::bvtrue()), triton::ast::bv(51, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(52, 52, op2), triton::ast::bvtrue()), triton::ast::bv(52, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(53, 53, op2), triton::ast::bvtrue()), triton::ast::bv(53, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(54, 54, op2), triton::ast::bvtrue()), triton::ast::bv(54, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(55, 55, op2), triton::ast::bvtrue()), triton::ast::bv(55, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(56, 56, op2), triton::ast::bvtrue()), triton::ast::bv(56, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(57, 57, op2), triton::ast::bvtrue()), triton::ast::bv(57, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(58, 58, op2), triton::ast::bvtrue()), triton::ast::bv(58, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(59, 59, op2), triton::ast::bvtrue()), triton::ast::bv(59, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(60, 60, op2), triton::ast::bvtrue()), triton::ast::bv(60, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(61, 61, op2), triton::ast::bvtrue()), triton::ast::bv(61, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(62, 62, op2), triton::ast::bvtrue()), triton::ast::bv(62, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(63, 63, op2), triton::ast::bvtrue()), triton::ast::bv(63, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
                     );
              break;
            default:
              throw std::runtime_error("Error: triton::arch::x86::semantics::bsf_s(): Invalid operand size.");
          }

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "BSF operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::zfBsf_s(inst, expr, src, op2);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void bsr_s(triton::arch::Instruction& inst) {
          auto dst     = inst.operands[0];
          auto src     = inst.operands[1];
          auto bvSize1 = dst.getBitSize();
          auto bvSize2 = src.getBitSize();

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          triton::ast::AbstractNode* node = nullptr;
          switch (src.getSize()) {
            case BYTE_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSR only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))
                     );
              break;
            case WORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSR only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))
                     );
              break;
            case DWORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSR only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(31, 31, op2), triton::ast::bvtrue()), triton::ast::bv(31, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(30, 30, op2), triton::ast::bvtrue()), triton::ast::bv(30, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(29, 29, op2), triton::ast::bvtrue()), triton::ast::bv(29, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(28, 28, op2), triton::ast::bvtrue()), triton::ast::bv(28, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(27, 27, op2), triton::ast::bvtrue()), triton::ast::bv(27, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(26, 26, op2), triton::ast::bvtrue()), triton::ast::bv(26, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(25, 25, op2), triton::ast::bvtrue()), triton::ast::bv(25, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(24, 24, op2), triton::ast::bvtrue()), triton::ast::bv(24, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(23, 23, op2), triton::ast::bvtrue()), triton::ast::bv(23, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(22, 22, op2), triton::ast::bvtrue()), triton::ast::bv(22, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(21, 21, op2), triton::ast::bvtrue()), triton::ast::bv(21, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(20, 20, op2), triton::ast::bvtrue()), triton::ast::bv(20, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(19, 19, op2), triton::ast::bvtrue()), triton::ast::bv(19, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(18, 18, op2), triton::ast::bvtrue()), triton::ast::bv(18, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(17, 17, op2), triton::ast::bvtrue()), triton::ast::bv(17, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(16, 16, op2), triton::ast::bvtrue()), triton::ast::bv(16, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))))))))))))))))))
                     );
              break;
            case QWORD_SIZE:
              node = triton::ast::ite(
                       triton::ast::equal(op2, triton::ast::bv(0, bvSize2)), /* Apply BSR only if op2 != 0 */
                       op1,
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(63, 63, op2), triton::ast::bvtrue()), triton::ast::bv(63, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(62, 62, op2), triton::ast::bvtrue()), triton::ast::bv(62, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(61, 61, op2), triton::ast::bvtrue()), triton::ast::bv(61, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(60, 60, op2), triton::ast::bvtrue()), triton::ast::bv(60, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(59, 59, op2), triton::ast::bvtrue()), triton::ast::bv(59, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(58, 58, op2), triton::ast::bvtrue()), triton::ast::bv(58, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(57, 57, op2), triton::ast::bvtrue()), triton::ast::bv(57, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(56, 56, op2), triton::ast::bvtrue()), triton::ast::bv(56, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(55, 55, op2), triton::ast::bvtrue()), triton::ast::bv(55, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(54, 54, op2), triton::ast::bvtrue()), triton::ast::bv(54, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(53, 53, op2), triton::ast::bvtrue()), triton::ast::bv(53, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(52, 52, op2), triton::ast::bvtrue()), triton::ast::bv(52, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(51, 51, op2), triton::ast::bvtrue()), triton::ast::bv(51, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(50, 50, op2), triton::ast::bvtrue()), triton::ast::bv(50, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(49, 49, op2), triton::ast::bvtrue()), triton::ast::bv(49, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(48, 48, op2), triton::ast::bvtrue()), triton::ast::bv(48, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(47, 47, op2), triton::ast::bvtrue()), triton::ast::bv(47, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(46, 46, op2), triton::ast::bvtrue()), triton::ast::bv(46, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(45, 45, op2), triton::ast::bvtrue()), triton::ast::bv(45, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(44, 44, op2), triton::ast::bvtrue()), triton::ast::bv(44, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(43, 43, op2), triton::ast::bvtrue()), triton::ast::bv(43, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(42, 42, op2), triton::ast::bvtrue()), triton::ast::bv(42, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(41, 41, op2), triton::ast::bvtrue()), triton::ast::bv(41, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(40, 40, op2), triton::ast::bvtrue()), triton::ast::bv(40, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(39, 39, op2), triton::ast::bvtrue()), triton::ast::bv(39, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(38, 38, op2), triton::ast::bvtrue()), triton::ast::bv(38, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(37, 37, op2), triton::ast::bvtrue()), triton::ast::bv(37, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(36, 36, op2), triton::ast::bvtrue()), triton::ast::bv(36, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(35, 35, op2), triton::ast::bvtrue()), triton::ast::bv(35, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(34, 34, op2), triton::ast::bvtrue()), triton::ast::bv(34, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(33, 33, op2), triton::ast::bvtrue()), triton::ast::bv(33, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(32, 32, op2), triton::ast::bvtrue()), triton::ast::bv(32, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(31, 31, op2), triton::ast::bvtrue()), triton::ast::bv(31, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(30, 30, op2), triton::ast::bvtrue()), triton::ast::bv(30, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(29, 29, op2), triton::ast::bvtrue()), triton::ast::bv(29, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(28, 28, op2), triton::ast::bvtrue()), triton::ast::bv(28, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(27, 27, op2), triton::ast::bvtrue()), triton::ast::bv(27, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(26, 26, op2), triton::ast::bvtrue()), triton::ast::bv(26, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(25, 25, op2), triton::ast::bvtrue()), triton::ast::bv(25, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(24, 24, op2), triton::ast::bvtrue()), triton::ast::bv(24, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(23, 23, op2), triton::ast::bvtrue()), triton::ast::bv(23, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(22, 22, op2), triton::ast::bvtrue()), triton::ast::bv(22, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(21, 21, op2), triton::ast::bvtrue()), triton::ast::bv(21, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(20, 20, op2), triton::ast::bvtrue()), triton::ast::bv(20, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(19, 19, op2), triton::ast::bvtrue()), triton::ast::bv(19, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(18, 18, op2), triton::ast::bvtrue()), triton::ast::bv(18, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(17, 17, op2), triton::ast::bvtrue()), triton::ast::bv(17, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(16, 16, op2), triton::ast::bvtrue()), triton::ast::bv(16, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(15, 15, op2), triton::ast::bvtrue()), triton::ast::bv(15, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(14, 14, op2), triton::ast::bvtrue()), triton::ast::bv(14, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(13, 13, op2), triton::ast::bvtrue()), triton::ast::bv(13, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(12, 12, op2), triton::ast::bvtrue()), triton::ast::bv(12, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(11, 11, op2), triton::ast::bvtrue()), triton::ast::bv(11, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(10, 10, op2), triton::ast::bvtrue()), triton::ast::bv(10, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(9, 9, op2), triton::ast::bvtrue()), triton::ast::bv(9, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(8, 8, op2), triton::ast::bvtrue()), triton::ast::bv(8, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(7, 7, op2), triton::ast::bvtrue()), triton::ast::bv(7, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(6, 6, op2), triton::ast::bvtrue()), triton::ast::bv(6, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(5, 5, op2), triton::ast::bvtrue()), triton::ast::bv(5, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(4, 4, op2), triton::ast::bvtrue()), triton::ast::bv(4, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(3, 3, op2), triton::ast::bvtrue()), triton::ast::bv(3, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(2, 2, op2), triton::ast::bvtrue()), triton::ast::bv(2, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(1, 1, op2), triton::ast::bvtrue()), triton::ast::bv(1, bvSize1),
                       triton::ast::ite(triton::ast::equal(triton::ast::extract(0, 0, op2), triton::ast::bvtrue()), triton::ast::bv(0, bvSize1),
                       triton::ast::bv(0, bvSize1)
                       ))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
                     );
              break;
            default:
              throw std::runtime_error("Error: triton::arch::x86::semantics::bsr_s(): Invalid operand size.");
          }

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "BSR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::zfBsf_s(inst, expr, src, op2); /* same as bsf */

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void bswap_s(triton::arch::Instruction& inst) {
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode *> bytes;
          switch (src.getSize()) {
            case QWORD_SIZE:
              bytes.push_front(triton::ast::extract(63, 56, op1));
              bytes.push_front(triton::ast::extract(55, 48, op1));
              bytes.push_front(triton::ast::extract(47, 40, op1));
              bytes.push_front(triton::ast::extract(39, 32, op1));
            case DWORD_SIZE:
              bytes.push_front(triton::ast::extract(31, 24, op1));
              bytes.push_front(triton::ast::extract(23, 16, op1));
            case WORD_SIZE:
              bytes.push_front(triton::ast::extract(15, 8, op1));
              bytes.push_front(triton::ast::extract(7,  0, op1));
              break;
            default:
              throw std::runtime_error("Error: triton::arch::x86::semantics::bswap_s(): Invalid operand size.");
          }

          auto node = triton::ast::concat(bytes);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, src, "BSWAP operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(src, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void call_s(triton::arch::Instruction& inst) {
          auto stack = TRITON_X86_REG_SP.getParent();

          /* Create the semantics - side effect */
          alignSubStack_s(inst, stack.getSize());

          auto stackValue = triton::api.getRegisterValue(stack).convert_to<triton::__uint>();
          auto pc         = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sp         = triton::arch::OperandWrapper(inst.popMemoryAccess(stackValue, stack.getSize()));
          auto src        = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics - side effect */
          auto node1 = triton::ast::bv(inst.getNextAddress(), pc.getBitSize());

          /* Create the semantics */
          auto node2 = op1;

          /* Create the symbolic expression */
          auto expr1 = triton::api.createSymbolicExpression(inst, node1, sp, "Saved Program Counter");

          /* Create symbolic expression */
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, pc, "Program Counter");

          /* Spread taint */
          expr1->isTainted = triton::api.taintAssignmentMemoryImmediate(sp.getMemory());
          expr2->isTainted = triton::api.taintAssignment(pc, src);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr2);
        }


        void cbw_s(triton::arch::Instruction& inst) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_AX);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);

          /* Create the semantics */
          auto node = triton::ast::sx(BYTE_SIZE_BIT, triton::ast::extract(BYTE_SIZE_BIT-1, 0, op1));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CBW operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cdqe_s(triton::arch::Instruction& inst) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);

          /* Create the semantics */
          auto node = triton::ast::sx(DWORD_SIZE_BIT, triton::ast::extract(DWORD_SIZE_BIT-1, 0, op1));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CDQE operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void clc_s(triton::arch::Instruction& inst) {
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_CF, "Clears carry flag");
          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cld_s(triton::arch::Instruction& inst) {
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_DF, "Clears direction flag");
          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmc_s(triton::arch::Instruction& inst) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);

          /* Create the semantics */
          auto node = triton::ast::bvnot(op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicFlagExpression(inst, node, dst.getRegister(), "CMC operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmova_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(cf);
          auto op4 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvand(triton::ast::bvnot(op3), triton::ast::bvnot(op4)), triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVA operation");

          /* Spread taint and condition flag */
          if ((!triton::api.getRegisterValue(TRITON_X86_REG_CF) & !triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == true) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovae_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(cf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVAE operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_CF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovb_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(cf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVB operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovbe_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(cf);
          auto op4 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(op3, op4), triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVBE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmove_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovg_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);
          auto op4 = triton::api.buildSymbolicOperand(of);
          auto op5 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op3, op4), op5), triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVG operation");

          /* Spread taint and condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == false) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovge_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);
          auto op4 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, op4), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVGE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) == triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovl_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);
          auto op4 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvxor(op3, op4), triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVL operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovle_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);
          auto op4 = triton::api.buildSymbolicOperand(of);
          auto op5 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op3, op4), op5), triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVBE operation");

          /* Spread taint and condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == true) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovne_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVNE operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovno_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVNO operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovnp_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto pf  = triton::arch::OperandWrapper(TRITON_X86_REG_PF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(pf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVNP operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_PF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovns_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvfalse()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVNS operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_SF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovo_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVO operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovp_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto pf  = triton::arch::OperandWrapper(TRITON_X86_REG_PF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(pf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVP operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_PF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmovs_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::api.buildSymbolicOperand(sf);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op3, triton::ast::bvtrue()), op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CMOVS operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF)) {
            expr->isTainted = triton::api.taintAssignment(dst, src);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmp_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::sx(dst.getBitSize() - src.getBitSize(), triton::api.buildSymbolicOperand(src));

          /* Create the semantics */
          auto node = triton::ast::bvsub(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicVolatileExpression(inst, node, "CMP operation");

          /* Spread taint */
          expr->isTainted = triton::api.isTainted(dst) | triton::api.isTainted(src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2, true);
          triton::arch::x86::semantics::cfSub_s(inst, expr, dst, op1, op2, true);
          triton::arch::x86::semantics::ofSub_s(inst, expr, dst, op1, op2, true);
          triton::arch::x86::semantics::pf_s(inst, expr, dst, true);
          triton::arch::x86::semantics::sf_s(inst, expr, dst, true);
          triton::arch::x86::semantics::zf_s(inst, expr, dst, true);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cmpxchg_s(triton::arch::Instruction& inst) {
          auto src1 = inst.operands[0];
          auto src2 = inst.operands[1];

          triton::arch::OperandWrapper accumulator(TRITON_X86_REG_AL);
          switch (src1.getSize()) {
            case WORD_SIZE:
              accumulator.setRegister(TRITON_X86_REG_AX);
              break;
            case DWORD_SIZE:
              accumulator.setRegister(TRITON_X86_REG_EAX);
              break;
            case QWORD_SIZE:
              accumulator.setRegister(TRITON_X86_REG_RAX);
              break;
          }

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(accumulator);
          auto op2 = triton::api.buildSymbolicOperand(src1);
          auto op3 = triton::api.buildSymbolicOperand(src2);

          /* Create the semantics */
          auto node1 = triton::ast::bvsub(op1, op2);
          auto node2 = triton::ast::ite(triton::ast::equal(op1, op2), op3, op2);
          auto node3 = triton::ast::ite(triton::ast::equal(op1, op2), op1, op2);

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicVolatileExpression(inst, node1, "CMP operation");
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, src1, "XCHG operation");
          auto expr3 = triton::api.createSymbolicExpression(inst, node3, accumulator, "XCHG operation");

          /* Spread taint */
          expr1->isTainted = triton::api.isTainted(accumulator) | triton::api.isTainted(src1);
          expr2->isTainted = triton::api.taintAssignment(src1, src2);
          expr3->isTainted = triton::api.taintAssignment(accumulator, src1);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr1, accumulator, op1, op2, true);
          triton::arch::x86::semantics::cfSub_s(inst, expr1, accumulator, op1, op2, true);
          triton::arch::x86::semantics::ofSub_s(inst, expr1, accumulator, op1, op2, true);
          triton::arch::x86::semantics::pf_s(inst, expr1, accumulator, true);
          triton::arch::x86::semantics::sf_s(inst, expr1, accumulator, true);
          triton::arch::x86::semantics::zf_s(inst, expr1, accumulator, true);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cqo_s(triton::arch::Instruction& inst) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_RDX);
          auto src = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics - TMP = 128 bitvec (RDX:RAX) */
          auto node1 = triton::ast::sx(QWORD_SIZE_BIT, op1);

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicVolatileExpression(inst, node1, "Temporary variable");

          /* Spread taint */
          expr1->isTainted = triton::api.isRegisterTainted(TRITON_X86_REG_RDX) | triton::api.isRegisterTainted(TRITON_X86_REG_RAX);

          /* Create the semantics - RAX = TMP[63...0] */
          auto node2 = triton::ast::extract(QWORD_SIZE_BIT-1, 0, triton::ast::reference(expr1->getId()));

          /* Create symbolic expression */
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, src, "CQO operation - RAX");

          /* Spread taint */
          expr2->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_RAX, expr1->isTainted);

          /* Create the semantics - RDX = TMP[127...64] */
          auto node3 = triton::ast::extract(DQWORD_SIZE_BIT-1, QWORD_SIZE_BIT, triton::ast::reference(expr1->getId()));

          /* Create symbolic expression */
          auto expr3 = triton::api.createSymbolicExpression(inst, node3, dst, "CQO operation - RDX");

          /* Spread taint */
          expr3->isTainted = triton::api.setTaintRegister(TRITON_X86_REG_RDX, expr1->isTainted);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void cwde_s(triton::arch::Instruction& inst) {
          auto dst = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);

          /* Create the semantics */
          auto node = triton::ast::sx(WORD_SIZE_BIT, triton::ast::extract(WORD_SIZE_BIT-1, 0, op1));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "CWDE operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void dec_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::bv(1, dst.getBitSize());

          /* Create the semantics */
          auto node = triton::ast::bvsub(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "DEC operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofSub_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void div_s(triton::arch::Instruction& inst) {
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto divisor = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          switch (src.getSize()) {

            case BYTE_SIZE: {
              /* AX */
              auto ax = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto dividend = triton::api.buildSymbolicOperand(ax);
              /* res = AX / Source */
              auto result = triton::ast::bvudiv(dividend, triton::ast::zx(BYTE_SIZE_BIT, divisor));
              /* mod = AX % Source */
              auto mod = triton::ast::bvurem(dividend, triton::ast::zx(BYTE_SIZE_BIT, divisor));
              /* AH = mod */
              /* AL = res */
              auto node = triton::ast::concat(
                            triton::ast::extract((BYTE_SIZE_BIT - 1), 0, mod),   /* AH = mod */
                            triton::ast::extract((BYTE_SIZE_BIT - 1), 0, result) /* AL = res */
                          );
              /* Create symbolic expression */
              auto expr = triton::api.createSymbolicExpression(inst, node, ax, "DIV operation");
              /* Apply the taint */
              expr->isTainted = triton::api.taintUnion(ax, src);
              break;
            }

            case WORD_SIZE: {
              /* DX:AX */
              auto dx = triton::arch::OperandWrapper(TRITON_X86_REG_DX);
              auto ax = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(dx), triton::api.buildSymbolicOperand(ax));
              /* res = DX:AX / Source */
              auto result = triton::ast::extract((WORD_SIZE_BIT - 1), 0, triton::ast::bvudiv(dividend, triton::ast::zx(WORD_SIZE_BIT, divisor)));
              /* mod = DX:AX % Source */
              auto mod = triton::ast::extract((WORD_SIZE_BIT - 1), 0, triton::ast::bvurem(dividend, triton::ast::zx(WORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for AX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, ax, "DIV operation");
              /* Apply the taint for AX */
              expr1->isTainted = triton::api.taintUnion(ax, src);
              /* Create the symbolic expression for DX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, dx, "DIV operation");
              /* Apply the taint for DX */
              expr2->isTainted = triton::api.taintUnion(dx, src);
              break;
            }

            case DWORD_SIZE: {
              /* EDX:EAX */
              auto edx = triton::arch::OperandWrapper(TRITON_X86_REG_EDX);
              auto eax = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(edx), triton::api.buildSymbolicOperand(eax));
              /* res = EDX:EAX / Source */
              auto result = triton::ast::extract((DWORD_SIZE_BIT - 1), 0, triton::ast::bvudiv(dividend, triton::ast::zx(DWORD_SIZE_BIT, divisor)));
              /* mod = EDX:EAX % Source */
              auto mod = triton::ast::extract((DWORD_SIZE_BIT - 1), 0, triton::ast::bvurem(dividend, triton::ast::zx(DWORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for EAX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, eax, "DIV operation");
              /* Apply the taint for EAX */
              expr1->isTainted = triton::api.taintUnion(eax, src);
              /* Create the symbolic expression for EDX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, edx, "DIV operation");
              /* Apply the taint for EDX */
              expr2->isTainted = triton::api.taintUnion(edx, src);
              break;
            }

            case QWORD_SIZE: {
              /* RDX:RAX */
              auto rdx = triton::arch::OperandWrapper(TRITON_X86_REG_RDX);
              auto rax = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(rdx), triton::api.buildSymbolicOperand(rax));
              /* res = RDX:RAX / Source */
              auto result = triton::ast::extract((QWORD_SIZE_BIT - 1), 0, triton::ast::bvudiv(dividend, triton::ast::zx(QWORD_SIZE_BIT, divisor)));
              /* mod = RDX:RAX % Source */
              auto mod = triton::ast::extract((QWORD_SIZE_BIT - 1), 0, triton::ast::bvurem(dividend, triton::ast::zx(QWORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for RAX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, rax, "DIV operation");
              /* Apply the taint for EAX */
              expr1->isTainted = triton::api.taintUnion(rax, src);
              /* Create the symbolic expression for RDX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, rdx, "DIV operation");
              /* Apply the taint for EDX */
              expr2->isTainted = triton::api.taintUnion(rdx, src);
              break;
            }

          }

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void idiv_s(triton::arch::Instruction& inst) {
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto divisor = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          switch (src.getSize()) {

            case BYTE_SIZE: {
              /* AX */
              auto ax = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto dividend = triton::api.buildSymbolicOperand(ax);
              /* res = AX / Source */
              auto result = triton::ast::bvsdiv(dividend, triton::ast::sx(BYTE_SIZE_BIT, divisor));
              /* mod = AX % Source */
              auto mod = triton::ast::bvsrem(dividend, triton::ast::sx(BYTE_SIZE_BIT, divisor));
              /* AH = mod */
              /* AL = res */
              auto node = triton::ast::concat(
                            triton::ast::extract((BYTE_SIZE_BIT - 1), 0, mod),   /* AH = mod */
                            triton::ast::extract((BYTE_SIZE_BIT - 1), 0, result) /* AL = res */
                          );
              /* Create symbolic expression */
              auto expr = triton::api.createSymbolicExpression(inst, node, ax, "IDIV operation");
              /* Apply the taint */
              expr->isTainted = triton::api.taintUnion(ax, src);
              break;
            }

            case WORD_SIZE: {
              /* DX:AX */
              auto dx = triton::arch::OperandWrapper(TRITON_X86_REG_DX);
              auto ax = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(dx), triton::api.buildSymbolicOperand(ax));
              /* res = DX:AX / Source */
              auto result = triton::ast::extract((WORD_SIZE_BIT - 1), 0, triton::ast::bvsdiv(dividend, triton::ast::sx(WORD_SIZE_BIT, divisor)));
              /* mod = DX:AX % Source */
              auto mod = triton::ast::extract((WORD_SIZE_BIT - 1), 0, triton::ast::bvsrem(dividend, triton::ast::sx(WORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for AX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, ax, "IDIV operation");
              /* Apply the taint for AX */
              expr1->isTainted = triton::api.taintUnion(ax, src);
              /* Create the symbolic expression for DX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, dx, "IDIV operation");
              /* Apply the taint for DX */
              expr2->isTainted = triton::api.taintUnion(dx, src);
              break;
            }

            case DWORD_SIZE: {
              /* EDX:EAX */
              auto edx = triton::arch::OperandWrapper(TRITON_X86_REG_EDX);
              auto eax = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(edx), triton::api.buildSymbolicOperand(eax));
              /* res = EDX:EAX / Source */
              auto result = triton::ast::extract((DWORD_SIZE_BIT - 1), 0, triton::ast::bvsdiv(dividend, triton::ast::sx(DWORD_SIZE_BIT, divisor)));
              /* mod = EDX:EAX % Source */
              auto mod = triton::ast::extract((DWORD_SIZE_BIT - 1), 0, triton::ast::bvsrem(dividend, triton::ast::sx(DWORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for EAX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, eax, "IDIV operation");
              /* Apply the taint for EAX */
              expr1->isTainted = triton::api.taintUnion(eax, src);
              /* Create the symbolic expression for EDX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, edx, "IDIV operation");
              /* Apply the taint for EDX */
              expr2->isTainted = triton::api.taintUnion(edx, src);
              break;
            }

            case QWORD_SIZE: {
              /* RDX:RAX */
              auto rdx = triton::arch::OperandWrapper(TRITON_X86_REG_RDX);
              auto rax = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);
              auto dividend = triton::ast::concat(triton::api.buildSymbolicOperand(rdx), triton::api.buildSymbolicOperand(rax));
              /* res = RDX:RAX / Source */
              auto result = triton::ast::extract((QWORD_SIZE_BIT - 1), 0, triton::ast::bvsdiv(dividend, triton::ast::sx(QWORD_SIZE_BIT, divisor)));
              /* mod = RDX:RAX % Source */
              auto mod = triton::ast::extract((QWORD_SIZE_BIT - 1), 0, triton::ast::bvsrem(dividend, triton::ast::sx(QWORD_SIZE_BIT, divisor)));
              /* Create the symbolic expression for RAX */
              auto expr1 = triton::api.createSymbolicExpression(inst, result, rax, "IDIV operation");
              /* Apply the taint for EAX */
              expr1->isTainted = triton::api.taintUnion(rax, src);
              /* Create the symbolic expression for RDX */
              auto expr2 = triton::api.createSymbolicExpression(inst, mod, rdx, "IDIV operation");
              /* Apply the taint for EDX */
              expr2->isTainted = triton::api.taintUnion(rdx, src);
              break;
            }

          }

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void imul_s(triton::arch::Instruction& inst) {
          switch (inst.operands.size()) {

            /* one operand */
            case 1: {
              auto src = inst.operands[0];

              /* size of the Operand */
              switch (src.getSize()) {

                /* dst = AX */
                case BYTE_SIZE: {
                  auto ax   = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
                  auto al   = triton::arch::OperandWrapper(TRITON_X86_REG_AL);
                  auto op1  = triton::api.buildSymbolicOperand(al);
                  auto op2  = triton::api.buildSymbolicOperand(src);
                  auto node = triton::ast::bvmul(triton::ast::sx(BYTE_SIZE_BIT, op1), triton::ast::sx(BYTE_SIZE_BIT, op2));
                  auto expr = triton::api.createSymbolicExpression(inst, node, ax, "IMUL operation");
                  expr->isTainted = triton::api.taintUnion(ax, src);
                  triton::arch::x86::semantics::cfImul_s(inst, expr, al, triton::ast::bvmul(op1, op2), node);
                  triton::arch::x86::semantics::ofImul_s(inst, expr, al, triton::ast::bvmul(op1, op2), node);
                  break;
                }

                /* dst = DX:AX */
                case WORD_SIZE: {
                  auto ax    = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
                  auto dx    = triton::arch::OperandWrapper(TRITON_X86_REG_DX);
                  auto op1   = triton::api.buildSymbolicOperand(ax);
                  auto op2   = triton::api.buildSymbolicOperand(src);
                  auto node  = triton::ast::bvmul(triton::ast::sx(WORD_SIZE_BIT, op1), triton::ast::sx(WORD_SIZE_BIT, op2));
                  auto expr1 = triton::api.createSymbolicExpression(inst, triton::ast::extract(WORD_SIZE_BIT-1, 0, node), ax, "IMUL operation");
                  auto expr2 = triton::api.createSymbolicExpression(inst, triton::ast::extract(DWORD_SIZE_BIT-1, WORD_SIZE_BIT, node), dx, "IMUL operation");
                  expr1->isTainted = triton::api.taintUnion(ax, src);
                  expr2->isTainted = triton::api.taintUnion(dx, src);
                  triton::arch::x86::semantics::cfImul_s(inst, expr1, ax, triton::ast::bvmul(op1, op2), node);
                  triton::arch::x86::semantics::ofImul_s(inst, expr1, ax, triton::ast::bvmul(op1, op2), node);
                  break;
                }

                /* dst = EDX:EAX */
                case DWORD_SIZE: {
                  auto eax   = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);
                  auto edx   = triton::arch::OperandWrapper(TRITON_X86_REG_EDX);
                  auto op1   = triton::api.buildSymbolicOperand(eax);
                  auto op2   = triton::api.buildSymbolicOperand(src);
                  auto node  = triton::ast::bvmul(triton::ast::sx(DWORD_SIZE_BIT, op1), triton::ast::sx(DWORD_SIZE_BIT, op2));
                  auto expr1 = triton::api.createSymbolicExpression(inst, triton::ast::extract(DWORD_SIZE_BIT-1, 0, node), eax, "IMUL operation");
                  auto expr2 = triton::api.createSymbolicExpression(inst, triton::ast::extract(QWORD_SIZE_BIT-1, DWORD_SIZE_BIT, node), edx, "IMUL operation");
                  expr1->isTainted = triton::api.taintUnion(eax, src);
                  expr2->isTainted = triton::api.taintUnion(edx, src);
                  triton::arch::x86::semantics::cfImul_s(inst, expr1, eax, triton::ast::bvmul(op1, op2), node);
                  triton::arch::x86::semantics::ofImul_s(inst, expr1, eax, triton::ast::bvmul(op1, op2), node);
                  break;
                }

                /* dst = RDX:RAX */
                case QWORD_SIZE: {
                  auto rax   = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);
                  auto rdx   = triton::arch::OperandWrapper(TRITON_X86_REG_RDX);
                  auto op1   = triton::api.buildSymbolicOperand(rax);
                  auto op2   = triton::api.buildSymbolicOperand(src);
                  auto node  = triton::ast::bvmul(triton::ast::sx(QWORD_SIZE_BIT, op1), triton::ast::sx(QWORD_SIZE_BIT, op2));
                  auto expr1 = triton::api.createSymbolicExpression(inst, triton::ast::extract(QWORD_SIZE_BIT-1, 0, node), rax, "IMUL operation");
                  auto expr2 = triton::api.createSymbolicExpression(inst, triton::ast::extract(DQWORD_SIZE_BIT-1, QWORD_SIZE_BIT, node), rdx, "IMUL operation");
                  expr1->isTainted = triton::api.taintUnion(rax, src);
                  expr2->isTainted = triton::api.taintUnion(rdx, src);
                  triton::arch::x86::semantics::cfImul_s(inst, expr1, rax, triton::ast::bvmul(op1, op2), node);
                  triton::arch::x86::semantics::ofImul_s(inst, expr1, rax, triton::ast::bvmul(op1, op2), node);
                  break;
                }

              }
              break;
            }

            /* two operands */
            case 2: {
              auto dst  = inst.operands[0];
              auto src  = inst.operands[1];
              auto op1  = triton::api.buildSymbolicOperand(dst);
              auto op2  = triton::api.buildSymbolicOperand(src);
              auto node = triton::ast::bvmul(triton::ast::sx(dst.getBitSize(), op1), triton::ast::sx(src.getBitSize(), op2));
              auto expr = triton::api.createSymbolicExpression(inst, triton::ast::extract(dst.getBitSize()-1, 0, node), dst, "IMUL operation");
              expr->isTainted = triton::api.taintUnion(dst, src);
              triton::arch::x86::semantics::cfImul_s(inst, expr, dst, triton::ast::bvmul(op1, op2), node);
              triton::arch::x86::semantics::ofImul_s(inst, expr, dst, triton::ast::bvmul(op1, op2), node);
              break;
            }

            /* three operands */
            case 3: {
              auto dst  = inst.operands[0];
              auto src1 = inst.operands[1];
              auto src2 = inst.operands[2];
              auto op2  = triton::api.buildSymbolicOperand(src1);
              auto op3  = triton::api.buildSymbolicOperand(src2);
              auto node = triton::ast::bvmul(triton::ast::sx(src1.getBitSize(), op2), triton::ast::sx(src2.getBitSize(), op3));
              auto expr = triton::api.createSymbolicExpression(inst, triton::ast::extract(dst.getBitSize()-1, 0, node), dst, "IMUL operation");
              expr->isTainted = triton::api.taintUnion(dst, src1);
              expr->isTainted = triton::api.taintUnion(dst, src2);
              triton::arch::x86::semantics::cfImul_s(inst, expr, dst, triton::ast::bvmul(op2, op3), node);
              triton::arch::x86::semantics::ofImul_s(inst, expr, dst, triton::ast::bvmul(op2, op3), node);
              break;
            }

          }

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void inc_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::bv(1, dst.getBitSize());

          /* Create the semantics */
          auto node = triton::ast::bvadd(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "INC operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofAdd_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void ja_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto cf      = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(cf);
          auto op2 = triton::api.buildSymbolicOperand(zf);
          auto op3 = triton::api.buildSymbolicOperand(srcImm1);
          auto op4 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bvand(
                            triton::ast::bvnot(op1),
                            triton::ast::bvnot(op2)
                          ),
                          triton::ast::bvtrue()
                        ), op4, op3);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if ((!triton::api.getRegisterValue(TRITON_X86_REG_CF) & !triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == true)
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, cf);
          expr->isTainted = triton::api.taintUnion(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jae_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto cf      = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(cf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvfalse()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_CF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, cf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jb_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto cf      = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(cf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvtrue()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, cf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jbe_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto cf      = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(cf);
          auto op2 = triton::api.buildSymbolicOperand(zf);
          auto op3 = triton::api.buildSymbolicOperand(srcImm1);
          auto op4 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(op1, op2), triton::ast::bvtrue()), op4, op3);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF) | triton::api.getRegisterValue(TRITON_X86_REG_ZF))
            inst.setConditionTaken(true);


          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, cf);
          expr->isTainted = triton::api.taintUnion(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void je_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(zf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvtrue()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_ZF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jg_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(of);
          auto op3 = triton::api.buildSymbolicOperand(zf);
          auto op4 = triton::api.buildSymbolicOperand(srcImm1);
          auto op5 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op1, op2), op3), triton::ast::bvfalse()), op5, op4);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == false)
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);
          expr->isTainted = triton::api.taintUnion(pc, of);
          expr->isTainted = triton::api.taintUnion(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jge_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(of);
          auto op3 = triton::api.buildSymbolicOperand(srcImm1);
          auto op4 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, op2), op4, op3);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) == triton::api.getRegisterValue(TRITON_X86_REG_OF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);
          expr->isTainted = triton::api.taintUnion(pc, of);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jl_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(of);
          auto op3 = triton::api.buildSymbolicOperand(srcImm1);
          auto op4 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvxor(op1, op2), triton::ast::bvtrue()), op4, op3);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);
          expr->isTainted = triton::api.taintUnion(pc, of);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jle_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(of);
          auto op3 = triton::api.buildSymbolicOperand(zf);
          auto op4 = triton::api.buildSymbolicOperand(srcImm1);
          auto op5 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op1, op2), op3), triton::ast::bvtrue()), op5, op4);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == true)
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);
          expr->isTainted = triton::api.taintUnion(pc, of);
          expr->isTainted = triton::api.taintUnion(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jmp_s(triton::arch::Instruction& inst) {
          auto pc  = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = op1;

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, src);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jne_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto zf      = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(zf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvfalse()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_ZF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, zf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jno_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(of);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvfalse()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_OF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, of);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jnp_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto pf      = triton::arch::OperandWrapper(TRITON_X86_REG_PF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(pf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvfalse()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_PF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, pf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jns_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvfalse()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_SF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jo_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto of      = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(of);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvtrue()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_OF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, of);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void jp_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto pf      = triton::arch::OperandWrapper(TRITON_X86_REG_PF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(pf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvtrue()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_PF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, pf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void js_s(triton::arch::Instruction& inst) {
          auto pc      = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sf      = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto srcImm1 = triton::arch::OperandWrapper(ImmediateOperand(inst.getNextAddress(), pc.getSize()));
          auto srcImm2 = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sf);
          auto op2 = triton::api.buildSymbolicOperand(srcImm1);
          auto op3 = triton::api.buildSymbolicOperand(srcImm2);

          /* Create the semantics */
          auto node = triton::ast::ite(triton::ast::equal(op1, triton::ast::bvtrue()), op3, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Set condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF))
            inst.setConditionTaken(true);

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sf);

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void lea_s(triton::arch::Instruction& inst) {
          auto dst                = inst.operands[0].getRegister();
          auto srcDisp            = inst.operands[1].getMemory().getDisplacement();
          auto srcBase            = inst.operands[1].getMemory().getBaseRegister();
          auto srcIndex           = inst.operands[1].getMemory().getIndexRegister();
          auto srcScale           = inst.operands[1].getMemory().getScale();
          triton::uint32 leaSize  = 0;

          /* Setup LEA size */
          if (srcBase.isValid())
            leaSize = srcBase.getBitSize();
          else if (srcIndex.isValid())
            leaSize = srcIndex.getBitSize();
          else
            leaSize = srcDisp.getBitSize();

          /* Create symbolic operands */

          /* Displacement */
          auto op2 = triton::api.buildSymbolicImmediateOperand(srcDisp);
          if (leaSize > srcDisp.getBitSize())
            op2 = triton::ast::zx(leaSize - srcDisp.getBitSize(), op2);

          /* Base */
          triton::ast::AbstractNode* op3;
          if (srcBase.isValid())
            op3 = triton::api.buildSymbolicRegisterOperand(srcBase);
          else
            op3 = triton::ast::bv(0, leaSize);

          /* Base with PC */
          if (srcBase.isValid() && (srcBase.getParent().getId() == TRITON_X86_REG_PC.getId()))
            op3 = triton::ast::bvadd(op3, triton::ast::bv(inst.getOpcodesSize(), leaSize));

          /* Index */
          triton::ast::AbstractNode* op4;
          if (srcIndex.isValid())
            op4 = triton::api.buildSymbolicRegisterOperand(srcIndex);
          else
            op4 = triton::ast::bv(0, leaSize);

          /* Scale */
          auto op5 = triton::api.buildSymbolicImmediateOperand(srcScale);
          if (leaSize > srcScale.getBitSize())
            op5 = triton::ast::zx(leaSize - srcScale.getBitSize(), op5);

          /* Create the semantics */
          /* Effective address = Displacement + BaseReg + IndexReg * Scale */
          auto node = triton::ast::bvadd(op2, triton::ast::bvadd(op3, triton::ast::bvmul(op4, op5)));

          if (dst.getBitSize() > leaSize)
            node = triton::ast::zx(dst.getBitSize() - leaSize, node);

          if (dst.getBitSize() < leaSize)
            node = triton::ast::extract(dst.getAbstractHigh(), dst.getAbstractLow(), node);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicRegisterExpression(inst, node, dst, "LEA operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignmentRegisterRegister(dst, srcBase);
          expr->isTainted = triton::api.taintUnionRegisterRegister(dst, srcIndex);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void leave_s(triton::arch::Instruction& inst) {
          auto stack      = TRITON_X86_REG_SP.getParent();
          auto stackValue = triton::api.getRegisterValue(stack).convert_to<triton::__uint>();
          auto bp1        = triton::arch::OperandWrapper(inst.popMemoryAccess(stackValue, stack.getSize()));
          auto bp2        = triton::arch::OperandWrapper(TRITON_X86_REG_BP.getParent());
          auto sp         = triton::arch::OperandWrapper(stack);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(bp2);

          /* RSP = RBP */
          auto node1 = op1;

          /* Create the symbolic expression */
          auto expr1 = triton::api.createSymbolicExpression(inst, node1, sp, "Stack Pointer");

          /* Spread taint */
          expr1->isTainted = triton::api.taintAssignment(sp, bp2);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(bp1);

          /* RBP = pop() */
          auto node2 = op2;

          /* Create the symbolic expression */
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, bp2, "Stack Top Pointer");

          /* Spread taint */
          expr2->isTainted = triton::api.taintAssignment(bp2, bp1);

          /* Create the semantics - side effect */
          alignAddStack_s(inst, bp1.getSize());

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void mov_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOV operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movabs_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVABS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movapd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVAPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movaps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVAPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          triton::ast::AbstractNode* node = nullptr;

          switch (dst.getBitSize()) {
            /* GPR 32-bits */
            case DWORD_SIZE_BIT:
              node = triton::ast::extract(DWORD_SIZE_BIT-1, 0, op2);
              break;

            /* MMX 64-bits */
            case QWORD_SIZE_BIT:
              node = triton::ast::zx(DWORD_SIZE_BIT, triton::ast::extract(DWORD_SIZE_BIT-1, 0, op2));
              break;

            /* XMM 128-bits */
            case DQWORD_SIZE_BIT:
              node = triton::ast::zx(QWORD_SIZE_BIT + DWORD_SIZE_BIT, triton::ast::extract(DWORD_SIZE_BIT-1, 0, op2));
              break;
          }

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movddup_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(triton::ast::extract(QWORD_SIZE_BIT-1, 0, op2), triton::ast::extract(QWORD_SIZE_BIT-1, 0, op2));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVDDUP operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movdq2q_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::extract(QWORD_SIZE_BIT-1, 0, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVDQ2Q operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movdqa_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVDQA operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movdqu_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVDQU operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movhlps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((DQWORD_SIZE_BIT - 1), QWORD_SIZE_BIT, op1), /* Destination[127..64] unchanged */
                        triton::ast::extract((DQWORD_SIZE_BIT - 1), QWORD_SIZE_BIT, op2)  /* Destination[63..0] = Source[127..64]; */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVHLPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movhpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op2), /* Destination[127..64] = Source */
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op1)  /* Destination[63..0] unchanged */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVHPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movhps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op2), /* Destination[127..64] = Source */
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op1)  /* Destination[63..0] unchanged */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVHPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movlhps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op2), /* Destination[127..64] = Source[63..0] */
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op1)  /* Destination[63..0] unchanged */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVLHPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movlpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((DQWORD_SIZE_BIT - 1), QWORD_SIZE_BIT, op1), /* Destination[127..64] unchanged */
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op2)                /* Destination[63..0] = Source */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVLPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movlps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::concat(
                        triton::ast::extract((DQWORD_SIZE_BIT - 1), QWORD_SIZE_BIT, op1), /* Destination[127..64] unchanged */
                        triton::ast::extract((QWORD_SIZE_BIT - 1), 0, op2)                /* Destination[63..0] = Source */
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVLPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movmskpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::zx(30,                       /* Destination[2..31] = 0        */
                        triton::ast::concat(
                          triton::ast::extract(127, 127, op2),  /* Destination[1] = Source[127]; */
                          triton::ast::extract(63, 63, op2)     /* Destination[0] = Source[63];  */
                        )
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVMSKPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movmskps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode*> signs;

          signs.push_back(triton::ast::extract(127, 127, op2)); /* Destination[3] = Source[127]; */
          signs.push_back(triton::ast::extract(95, 95,   op2)); /* Destination[2] = Source[95];  */
          signs.push_back(triton::ast::extract(63, 63,   op2)); /* Destination[1] = Source[63];  */
          signs.push_back(triton::ast::extract(31, 31,   op2)); /* Destination[0] = Source[31];  */

          auto node = triton::ast::zx(28, triton::ast::concat(signs));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVMSKPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }

        void movntdq_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVNTDQ operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movnti_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVNTI operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movntpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVNTPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movntps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVNTPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movntq_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVNTQ operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movshdup_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode*> bytes;

          bytes.push_back(triton::ast::extract(127, 96, op2));
          bytes.push_back(triton::ast::extract(127, 96, op2));
          bytes.push_back(triton::ast::extract(63, 32, op2));
          bytes.push_back(triton::ast::extract(63, 32, op2));

          auto node = triton::ast::concat(bytes);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVSHDUP operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movsldup_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode*> bytes;

          bytes.push_back(triton::ast::extract(95, 64, op2));
          bytes.push_back(triton::ast::extract(95, 64, op2));
          bytes.push_back(triton::ast::extract(31, 0, op2));
          bytes.push_back(triton::ast::extract(31, 0, op2));

          auto node = triton::ast::concat(bytes);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVSLDUP operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movsx_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::sx(dst.getBitSize() - src.getBitSize(), op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVSX operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movsxd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::sx(dst.getBitSize() - src.getBitSize(), op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVSXD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void movzx_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::zx(dst.getBitSize() - src.getBitSize(), op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MOVZX operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void mul_s(triton::arch::Instruction& inst) {
          auto src2 = inst.operands[0];

          switch (src2.getSize()) {

            /* AX = AL * r/m8 */
            case BYTE_SIZE: {
              auto dst  = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto src1 = triton::arch::OperandWrapper(TRITON_X86_REG_AL);
              /* Create symbolic operands */
              auto op1 = triton::api.buildSymbolicOperand(src1);
              auto op2 = triton::api.buildSymbolicOperand(src2);
              /* Create the semantics */
              auto node = triton::ast::bvmul(triton::ast::zx(BYTE_SIZE_BIT, op1), triton::ast::zx(BYTE_SIZE_BIT, op2));
              /* Create symbolic expression */
              auto expr = triton::api.createSymbolicExpression(inst, node, dst, "MUL operation");
              /* Apply the taint */
              expr->isTainted = triton::api.taintUnion(dst, src2);
              /* Upate symbolic flags */
              auto ah = triton::ast::extract((WORD_SIZE_BIT - 1), BYTE_SIZE_BIT, node);
              triton::arch::x86::semantics::cfMul_s(inst, expr, src2, ah);
              triton::arch::x86::semantics::ofMul_s(inst, expr, src2, ah);
              break;
            }

            /* DX:AX = AX * r/m16 */
            case WORD_SIZE: {
              auto dst1 = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              auto dst2 = triton::arch::OperandWrapper(TRITON_X86_REG_DX);
              auto src1 = triton::arch::OperandWrapper(TRITON_X86_REG_AX);
              /* Create symbolic operands */
              auto op1 = triton::api.buildSymbolicOperand(src1);
              auto op2 = triton::api.buildSymbolicOperand(src2);
              /* Create the semantics */
              auto node = triton::ast::bvmul(triton::ast::zx(WORD_SIZE_BIT, op1), triton::ast::zx(WORD_SIZE_BIT, op2));
              /* Create symbolic expression for ax */
              auto ax = triton::ast::extract((WORD_SIZE_BIT - 1), 0, node);
              auto expr1 = triton::api.createSymbolicExpression(inst, ax, dst1, "MUL operation");
              /* Apply the taint */
              expr1->isTainted = triton::api.taintUnion(dst1, src2);
              /* Create symbolic expression for dx */
              auto dx = triton::ast::extract((DWORD_SIZE_BIT - 1), WORD_SIZE_BIT, node);
              auto expr2 = triton::api.createSymbolicExpression(inst, dx, dst2, "MUL operation");
              /* Apply the taint */
              expr2->isTainted = triton::api.taintUnion(dst2, src2);
              expr2->isTainted = triton::api.taintUnion(dst2, src1);
              /* Upate symbolic flags */
              triton::arch::x86::semantics::cfMul_s(inst, expr2, src2, dx);
              triton::arch::x86::semantics::ofMul_s(inst, expr2, src2, dx);
              break;
            }

            /* EDX:EAX = EAX * r/m32 */
            case DWORD_SIZE: {
              auto dst1 = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);
              auto dst2 = triton::arch::OperandWrapper(TRITON_X86_REG_EDX);
              auto src1 = triton::arch::OperandWrapper(TRITON_X86_REG_EAX);
              /* Create symbolic operands */
              auto op1 = triton::api.buildSymbolicOperand(src1);
              auto op2 = triton::api.buildSymbolicOperand(src2);
              /* Create the semantics */
              auto node = triton::ast::bvmul(triton::ast::zx(DWORD_SIZE_BIT, op1), triton::ast::zx(DWORD_SIZE_BIT, op2));
              /* Create symbolic expression for eax */
              auto eax = triton::ast::extract((DWORD_SIZE_BIT - 1), 0, node);
              auto expr1 = triton::api.createSymbolicExpression(inst, eax, dst1, "MUL operation");
              /* Apply the taint */
              expr1->isTainted = triton::api.taintUnion(dst1, src2);
              /* Create symbolic expression for edx */
              auto edx = triton::ast::extract((QWORD_SIZE_BIT - 1), DWORD_SIZE_BIT, node);
              auto expr2 = triton::api.createSymbolicExpression(inst, edx, dst2, "MUL operation");
              /* Apply the taint */
              expr2->isTainted = triton::api.taintUnion(dst2, src2);
              expr2->isTainted = triton::api.taintUnion(dst2, src1);
              /* Upate symbolic flags */
              triton::arch::x86::semantics::cfMul_s(inst, expr2, src2, edx);
              triton::arch::x86::semantics::ofMul_s(inst, expr2, src2, edx);
              break;
            }

            /* RDX:RAX = RAX * r/m64 */
            case QWORD_SIZE: {
              auto dst1 = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);
              auto dst2 = triton::arch::OperandWrapper(TRITON_X86_REG_RDX);
              auto src1 = triton::arch::OperandWrapper(TRITON_X86_REG_RAX);
              /* Create symbolic operands */
              auto op1 = triton::api.buildSymbolicOperand(src1);
              auto op2 = triton::api.buildSymbolicOperand(src2);
              /* Create the semantics */
              auto node = triton::ast::bvmul(triton::ast::zx(QWORD_SIZE_BIT, op1), triton::ast::zx(QWORD_SIZE_BIT, op2));
              /* Create symbolic expression for eax */
              auto rax = triton::ast::extract((QWORD_SIZE_BIT - 1), 0, node);
              auto expr1 = triton::api.createSymbolicExpression(inst, rax, dst1, "MUL operation");
              /* Apply the taint */
              expr1->isTainted = triton::api.taintUnion(dst1, src2);
              /* Create symbolic expression for rdx */
              auto rdx = triton::ast::extract((DQWORD_SIZE_BIT - 1), QWORD_SIZE_BIT, node);
              auto expr2 = triton::api.createSymbolicExpression(inst, rdx, dst2, "MUL operation");
              /* Apply the taint */
              expr2->isTainted = triton::api.taintUnion(dst2, src2);
              expr2->isTainted = triton::api.taintUnion(dst2, src1);
              /* Upate symbolic flags */
              triton::arch::x86::semantics::cfMul_s(inst, expr2, src2, rdx);
              triton::arch::x86::semantics::ofMul_s(inst, expr2, src2, rdx);
              break;
            }

          }

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void neg_s(triton::arch::Instruction& inst) {
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvneg(op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, src, "NEG operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintUnion(src, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::afNeg_s(inst, expr, src, op1);
          triton::arch::x86::semantics::cfNeg_s(inst, expr, src, op1);
          triton::arch::x86::semantics::ofNeg_s(inst, expr, src, op1);
          triton::arch::x86::semantics::pf_s(inst, expr, src);
          triton::arch::x86::semantics::sf_s(inst, expr, src);
          triton::arch::x86::semantics::zf_s(inst, expr, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void nop_s(triton::arch::Instruction& inst) {
          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void not_s(triton::arch::Instruction& inst) {
          auto src = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvnot(op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, src, "NOT operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintUnion(src, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void or_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "OR operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_CF, "Clears carry flag");
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_OF, "Clears overflow flag");
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void orpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ORPD operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void orps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ORPS operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pand_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PAND operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pandn_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvand(triton::ast::bvnot(op1), op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PANDN operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pcmpeqb_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode *> pck;
          for (triton::uint32 index = 0; index < dst.getSize(); index++) {
            uint32 high = (dst.getBitSize() - 1) - (index * BYTE_SIZE_BIT);
            uint32 low  = (dst.getBitSize() - BYTE_SIZE_BIT) - (index * BYTE_SIZE_BIT);
            pck.push_back(triton::ast::ite(
                            triton::ast::equal(
                              triton::ast::extract(high, low, op1),
                              triton::ast::extract(high, low, op2)),
                            triton::ast::bv(0xff, BYTE_SIZE_BIT),
                            triton::ast::bv(0x00, BYTE_SIZE_BIT))
                         );
          }

          auto node = triton::ast::concat(pck);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PCMPEQB operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pcmpeqd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode *> pck;
          for (triton::uint32 index = 0; index < dst.getSize() / DWORD_SIZE; index++) {
            uint32 high = (dst.getBitSize() - 1) - (index * DWORD_SIZE_BIT);
            uint32 low  = (dst.getBitSize() - DWORD_SIZE_BIT) - (index * DWORD_SIZE_BIT);
            pck.push_back(triton::ast::ite(
                            triton::ast::equal(
                              triton::ast::extract(high, low, op1),
                              triton::ast::extract(high, low, op2)),
                            triton::ast::bv(0xffffffff, DWORD_SIZE_BIT),
                            triton::ast::bv(0x00000000, DWORD_SIZE_BIT))
                         );
          }

          auto node = triton::ast::concat(pck);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PCMPEQD operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pcmpeqw_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode *> pck;
          for (triton::uint32 index = 0; index < dst.getSize() / WORD_SIZE; index++) {
            uint32 high = (dst.getBitSize() - 1) - (index * WORD_SIZE_BIT);
            uint32 low  = (dst.getBitSize() - WORD_SIZE_BIT) - (index * WORD_SIZE_BIT);
            pck.push_back(triton::ast::ite(
                            triton::ast::equal(
                              triton::ast::extract(high, low, op1),
                              triton::ast::extract(high, low, op2)),
                            triton::ast::bv(0xffff, WORD_SIZE_BIT),
                            triton::ast::bv(0x0000, WORD_SIZE_BIT))
                         );
          }

          auto node = triton::ast::concat(pck);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PCMPEQW operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pmovmskb_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          std::list<triton::ast::AbstractNode *> mskb;
          switch (src.getSize()) {
            case DQWORD_SIZE:
              mskb.push_back(triton::ast::extract(127, 127, op2));
              mskb.push_back(triton::ast::extract(119, 119, op2));
              mskb.push_back(triton::ast::extract(111, 111, op2));
              mskb.push_back(triton::ast::extract(103, 103, op2));
              mskb.push_back(triton::ast::extract(95,  95,  op2));
              mskb.push_back(triton::ast::extract(87,  87,  op2));
              mskb.push_back(triton::ast::extract(79,  79,  op2));
              mskb.push_back(triton::ast::extract(71,  71,  op2));

            case QWORD_SIZE:
              mskb.push_back(triton::ast::extract(63,  63,  op2));
              mskb.push_back(triton::ast::extract(55,  55,  op2));
              mskb.push_back(triton::ast::extract(47,  47,  op2));
              mskb.push_back(triton::ast::extract(39,  39,  op2));
              mskb.push_back(triton::ast::extract(31,  31,  op2));
              mskb.push_back(triton::ast::extract(23,  23,  op2));
              mskb.push_back(triton::ast::extract(15,  15,  op2));
              mskb.push_back(triton::ast::extract(7,   7,   op2));
          }

          auto node = triton::ast::zx(dst.getBitSize() - mskb.size(), triton::ast::concat(mskb));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PMOVMSKB operation");

          /* Apply the taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pop_s(triton::arch::Instruction& inst) {
          auto stack      = TRITON_X86_REG_SP.getParent();
          auto stackValue = triton::api.getRegisterValue(stack).convert_to<triton::__uint>();
          auto dst        = inst.operands[0];
          auto src        = triton::arch::OperandWrapper(inst.popMemoryAccess(stackValue, stack.getSize()));

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = op1;

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "POP operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Create the semantics - side effect */
          alignAddStack_s(inst, src.getSize());

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void por_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "POR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void push_s(triton::arch::Instruction& inst) {
          auto stack = TRITON_X86_REG_SP.getParent();

          /* Create the semantics - side effect */
          alignSubStack_s(inst, stack.getSize());

          auto stackValue = triton::api.getRegisterValue(stack).convert_to<triton::__uint>();
          auto dst        = triton::arch::OperandWrapper(inst.popMemoryAccess(stackValue, stack.getSize()));
          auto src        = inst.operands[0];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::zx(dst.getBitSize() - src.getBitSize(), op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PUSH operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void pxor_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvxor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "PXOR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void rcl_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];
          auto srcCf = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          /*
           * Note that the SMT2-LIB doesn't support expression as rotate value.
           * The op2 must be the value of the concretization.
           */
          auto op2 = triton::ast::decimal(src.getConcreteValue());
          auto op3 = triton::api.buildSymbolicOperand(srcCf);

          /* Create the semantics */
          auto node1 = triton::ast::bvrol(op2, triton::ast::concat(op3, op1));

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicVolatileExpression(inst, node1, "RCL tempory operation");

          /* Spread taint */
          expr1->isTainted = triton::api.isTainted(dst) | triton::api.isTainted(src);

          /* Create the semantics */
          auto node2 = triton::ast::extract(dst.getBitSize()-1, 0, node1);

          /* Create symbolic expression */
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, dst, "RCL operation");

          /* Spread taint */
          expr2->isTainted = triton::api.taintUnion(dst, src);
          expr2->isTainted = triton::api.taintUnion(dst, srcCf);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfRcl_s(inst, expr1, dst, op2, true);
          triton::arch::x86::semantics::ofRol_s(inst, expr1, dst, op2, true); /* Same as ROL */

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void rcr_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];
          auto srcCf = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          /*
           * Note that the SMT2-LIB doesn't support expression as rotate value.
           * The op2 must be the value of the concretization.
           */
          auto op2 = triton::ast::decimal(src.getConcreteValue());
          auto op3 = triton::api.buildSymbolicOperand(srcCf);

          /* Create the semantics */
          auto node1 = triton::ast::bvror(op2, triton::ast::concat(op3, op1));

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicVolatileExpression(inst, node1, "RCR tempory operation");

          /* Spread taint */
          expr1->isTainted = triton::api.isTainted(dst) | triton::api.isTainted(src);

          /* Create the semantics */
          auto node2 = triton::ast::extract(dst.getBitSize()-1, 0, node1);

          /* Create symbolic expression */
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, dst, "RCR operation");

          /* Spread taint */
          expr2->isTainted = triton::api.taintUnion(dst, src);
          expr2->isTainted = triton::api.taintUnion(dst, srcCf);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfRcl_s(inst, expr1, dst, op2, true); /* Same as RCL */
          triton::arch::x86::semantics::ofRor_s(inst, expr1, dst, op2, true); /* Same as ROR */

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void ret_s(triton::arch::Instruction& inst) {
          auto stack      = TRITON_X86_REG_SP.getParent();
          auto stackValue = triton::api.getRegisterValue(stack).convert_to<triton::__uint>();
          auto pc         = triton::arch::OperandWrapper(TRITON_X86_REG_PC);
          auto sp         = triton::arch::OperandWrapper(inst.popMemoryAccess(stackValue, stack.getSize()));

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(sp);

          /* Create the semantics */
          auto node = op1;

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, pc, "Program Counter");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(pc, sp);

          /* Create the semantics - side effect */
          alignAddStack_s(inst, sp.getSize());

          /* Create the semantics - side effect */
          if (inst.operands.size() > 0)
            alignAddStack_s(inst, inst.operands[0].getImmediate().getValue());

          /* Create the path constraint */
          triton::api.addPathConstraint(expr);
        }


        void rol_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          /*
           * Note that the SMT2-LIB doesn't support expression as rotate value.
           * The op2 must be the value of the concretization.
           */
          auto op2 = triton::ast::decimal(src.getConcreteValue());

          /* Create the semantics */
          auto node = triton::ast::bvrol(op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ROL operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfRol_s(inst, expr, dst, op2);
          triton::arch::x86::semantics::ofRol_s(inst, expr, dst, op2);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void ror_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          /*
           * Note that the SMT2-LIB doesn't support expression as rotate value.
           * The op2 must be the value of the concretization.
           */
          auto op2 = triton::ast::decimal(src.getConcreteValue());

          /* Create the semantics */
          auto node = triton::ast::bvror(op2, op1);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "ROR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfRor_s(inst, expr, dst, op2);
          triton::arch::x86::semantics::ofRor_s(inst, expr, dst, op2);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void sar_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::zx(dst.getBitSize() - src.getBitSize(), triton::api.buildSymbolicOperand(src));

          /* Create the semantics */
          auto node = triton::ast::bvashr(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SAR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfSar_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofSar_s(inst, expr, dst, op2);
          triton::arch::x86::semantics::pfShl_s(inst, expr, dst, op2); /* Same that shl */
          triton::arch::x86::semantics::sfShl_s(inst, expr, dst, op2); /* Same that shl */
          triton::arch::x86::semantics::zfShl_s(inst, expr, dst, op2); /* Same that shl */

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void sbb_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];
          auto srcCf = triton::arch::OperandWrapper(RegisterOperand(TRITON_X86_REG_CF));

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);
          auto op3 = triton::ast::zx(src.getBitSize()-1, triton::api.buildSymbolicOperand(srcCf));

          /* Create the semantics */
          auto node = triton::ast::bvsub(op1, triton::ast::bvadd(op2, op3));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SBB operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);
          expr->isTainted = triton::api.taintUnion(dst, srcCf);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::cfSub_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofSub_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void seta_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(cf);
          auto op3 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(
                          triton::ast::bvand(
                            triton::ast::bvnot(op2),
                            triton::ast::bvnot(op3)
                          ),
                          triton::ast::bvtrue()
                        ),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETA operation");

          /* Spread taint and condition flag */
          if (((!triton::api.getRegisterValue(TRITON_X86_REG_CF) & !triton::api.getRegisterValue(TRITON_X86_REG_ZF))) == true) {
            expr->isTainted = triton::api.taintUnion(dst, cf);
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setae_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(cf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETAE operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_CF)) {
            expr->isTainted = triton::api.taintUnion(dst, cf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setb_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(cf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETB operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF)) {
            expr->isTainted = triton::api.taintUnion(dst, cf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setbe_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto cf  = triton::arch::OperandWrapper(TRITON_X86_REG_CF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(cf);
          auto op3 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(triton::ast::bvor(op2, op3), triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETBE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_CF) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintUnion(dst, cf);
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void sete_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setg_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);
          auto op3 = triton::api.buildSymbolicOperand(of);
          auto op4 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op2, op3), op4), triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETG operation");

          /* Spread taint and condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == false) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            expr->isTainted = triton::api.taintUnion(dst, of);
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setge_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);
          auto op3 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, op3),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETGE operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) == triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            expr->isTainted = triton::api.taintUnion(dst, of);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setl_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);
          auto op3 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(triton::ast::bvxor(op2, op3), triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETL operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            expr->isTainted = triton::api.taintUnion(dst, of);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setle_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);
          auto op3 = triton::api.buildSymbolicOperand(of);
          auto op4 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(triton::ast::bvor(triton::ast::bvxor(op2, op3), op4), triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETLE operation");

          /* Spread taint and condition flag */
          if (((triton::api.getRegisterValue(TRITON_X86_REG_SF) ^ triton::api.getRegisterValue(TRITON_X86_REG_OF)) | triton::api.getRegisterValue(TRITON_X86_REG_ZF)) == true) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            expr->isTainted = triton::api.taintUnion(dst, of);
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setne_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto zf  = triton::arch::OperandWrapper(TRITON_X86_REG_ZF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(zf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETNE operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_ZF)) {
            expr->isTainted = triton::api.taintUnion(dst, zf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setno_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETNO operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintUnion(dst, of);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setnp_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto pf  = triton::arch::OperandWrapper(TRITON_X86_REG_PF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(pf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETNP operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_PF)) {
            expr->isTainted = triton::api.taintUnion(dst, pf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setns_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvfalse()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETNS operation");

          /* Spread taint and condition flag */
          if (!triton::api.getRegisterValue(TRITON_X86_REG_SF)) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void seto_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto of  = triton::arch::OperandWrapper(TRITON_X86_REG_OF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(of);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETO operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_OF)) {
            expr->isTainted = triton::api.taintUnion(dst, of);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void setp_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto pf  = triton::arch::OperandWrapper(TRITON_X86_REG_PF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(pf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETP operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_PF)) {
            expr->isTainted = triton::api.taintUnion(dst, pf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void sets_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto sf  = triton::arch::OperandWrapper(TRITON_X86_REG_SF);

          /* Create symbolic operands */
          auto op2 = triton::api.buildSymbolicOperand(sf);

          /* Create the semantics */
          auto node = triton::ast::ite(
                        triton::ast::equal(op2, triton::ast::bvtrue()),
                        triton::ast::bv(1, dst.getBitSize()),
                        triton::ast::bv(0, dst.getBitSize())
                      );

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SETS operation");

          /* Spread taint and condition flag */
          if (triton::api.getRegisterValue(TRITON_X86_REG_SF)) {
            expr->isTainted = triton::api.taintUnion(dst, sf);
            inst.setConditionTaken(true);
          }
          else
            expr->isTainted = triton::api.taintUnion(dst, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void shl_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::zx(dst.getBitSize() - src.getBitSize(), triton::api.buildSymbolicOperand(src));

          /* Create the semantics */
          auto node = triton::ast::bvshl(op1, triton::ast::bvand(op2, triton::ast::bv(dst.getBitSize()-1, dst.getBitSize())));

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SHL operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfShl_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofShl_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pfShl_s(inst, expr, dst, op2);
          triton::arch::x86::semantics::sfShl_s(inst, expr, dst, op2);
          triton::arch::x86::semantics::zfShl_s(inst, expr, dst, op2);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void shr_s(triton::arch::Instruction& inst) {
          auto dst   = inst.operands[0];
          auto src   = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::ast::zx(dst.getBitSize() - src.getBitSize(), triton::api.buildSymbolicOperand(src));

          /* Create the semantics */
          auto node = triton::ast::bvlshr(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SHR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::cfShr_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofShr_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pfShl_s(inst, expr, dst, op2); /* Same that shl */
          triton::arch::x86::semantics::sfShl_s(inst, expr, dst, op2); /* Same that shl */
          triton::arch::x86::semantics::zfShl_s(inst, expr, dst, op2); /* Same that shl */

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void stc_s(triton::arch::Instruction& inst) {
          triton::arch::x86::semantics::setFlag_s(inst, TRITON_X86_REG_CF, "Sets carry flag");
          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void std_s(triton::arch::Instruction& inst) {
          triton::arch::x86::semantics::setFlag_s(inst, TRITON_X86_REG_DF, "Sets direction flag");
          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void sub_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvsub(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "SUB operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::af_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::cfSub_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::ofSub_s(inst, expr, dst, op1, op2);
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void test_s(triton::arch::Instruction& inst) {
          auto src1 = inst.operands[0];
          auto src2 = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(src1);
          auto op2 = triton::api.buildSymbolicOperand(src2);

          /* Create the semantics */
          auto node = triton::ast::bvand(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicVolatileExpression(inst, node, "AND operation");

          /* Spread taint */
          expr->isTainted = triton::api.isTainted(src1) | triton::api.isTainted(src2);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_CF, "Clears carry flag");
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_OF, "Clears overflow flag");
          triton::arch::x86::semantics::pf_s(inst, expr, src1, true);
          triton::arch::x86::semantics::sf_s(inst, expr, src1, true);
          triton::arch::x86::semantics::zf_s(inst, expr, src1, true);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void vmovdqa_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create the semantics */
          auto node = triton::api.buildSymbolicOperand(src);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "VMOVDQA operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintAssignment(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void xadd_s(triton::arch::Instruction& inst) {
          auto dst  = inst.operands[0];
          auto src  = inst.operands[1];
          bool dstT = triton::api.isTainted(dst);
          bool srcT = triton::api.isTainted(src);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node1 = op2;
          auto node2 = op1;

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicExpression(inst, node1, dst, "XCHG operation");
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, src, "XCHG operation");

          /* Spread taint */
          expr1->isTainted = triton::api.setTaint(dst, srcT);
          expr2->isTainted = triton::api.setTaint(src, dstT);

          /* Create symbolic operands */
          op1 = triton::api.buildSymbolicOperand(dst);
          op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node3 = triton::ast::bvadd(op1, op2);

          /* Create symbolic expression */
          auto expr3 = triton::api.createSymbolicExpression(inst, node3, dst, "ADD operation");

          /* Spread taint */
          expr3->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void xchg_s(triton::arch::Instruction& inst) {
          auto dst  = inst.operands[0];
          auto src  = inst.operands[1];
          bool dstT = triton::api.isTainted(dst);
          bool srcT = triton::api.isTainted(src);

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node1 = op2;
          auto node2 = op1;

          /* Create symbolic expression */
          auto expr1 = triton::api.createSymbolicExpression(inst, node1, dst, "XCHG operation");
          auto expr2 = triton::api.createSymbolicExpression(inst, node2, src, "XCHG operation");

          /* Spread taint */
          expr1->isTainted = triton::api.setTaint(dst, srcT);
          expr2->isTainted = triton::api.setTaint(src, dstT);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void xor_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvxor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "XOR operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate symbolic flags */
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_CF, "Clears carry flag");
          triton::arch::x86::semantics::clearFlag_s(inst, TRITON_X86_REG_OF, "Clears overflow flag");
          triton::arch::x86::semantics::pf_s(inst, expr, dst);
          triton::arch::x86::semantics::sf_s(inst, expr, dst);
          triton::arch::x86::semantics::zf_s(inst, expr, dst);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void xorpd_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvxor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "XORPD operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


        void xorps_s(triton::arch::Instruction& inst) {
          auto dst = inst.operands[0];
          auto src = inst.operands[1];

          /* Create symbolic operands */
          auto op1 = triton::api.buildSymbolicOperand(dst);
          auto op2 = triton::api.buildSymbolicOperand(src);

          /* Create the semantics */
          auto node = triton::ast::bvxor(op1, op2);

          /* Create symbolic expression */
          auto expr = triton::api.createSymbolicExpression(inst, node, dst, "XORPS operation");

          /* Spread taint */
          expr->isTainted = triton::api.taintUnion(dst, src);

          /* Upate the symbolic control flow */
          triton::arch::x86::semantics::controlFlow_s(inst);
        }


      }; /* semantics namespace */
    }; /* x86 namespace */
  }; /* arch namespace */
}; /* triton namespace */

