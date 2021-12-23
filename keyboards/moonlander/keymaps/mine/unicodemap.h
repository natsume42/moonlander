#pragma once
#include QMK_KEYBOARD_H

// clang-format off
enum unicode_names {
    /* prgSym layer */
    SUB1, SUB2, SUB3, SUB4, LONGS,
    LT, GT, EQ,
    ALEQ, LE, GE,
    PLUS, 
    PLMNS, 

    /* txtSym layer */
    SUP1, SUP2, SUP3, SUP4,
    HELLP, EMPTY_SET, SGR, SGL,
    POUND, EUR, DGR, DGL,
    CENT, DOLLAR, ARRL, ARRR, ARRLR,
    DARRL, DARRR, DARRLR,

    CEDILLA, MACRON,
    SLWQM, SLQM, SRQM, EM_DASH, CSHS,
    DLWQM, DLQM, DRQM, EN_DASH,
    WCIRCLE, CHCKM, XSIGN, BULLET,
    MDOT,
    NNBS,

    /* numPad */
    COLON,
};
// clang-format on

const uint32_t PROGMEM unicode_map[] = {
    /* prgSym layer */
    [SUB1]  = 0x2081,  // ₁
    [SUB2]  = 0x2082,  // ₂
    [SUB3]  = 0x2083,  // ₃
    [SUB4]  = 0x2084,  // ₄
    [LONGS] = 0x017f,  // ſ
    [LT]    = 0x003c,  // <
    [GT]    = 0x003e,  // >
    [EQ]    = 0x003d,  // =
    [ALEQ]  = 0x2248,  // ≈
    [LE]    = 0x2264,  // ≤
    [GE]    = 0x2265,  // ≥
    [PLUS]  = 0x002b,  // +
    [PLMNS] = 0x00B1,  // ±

    /* txtSym layer */
    [SUP1]      = 0x00b9,  // ¹
    [SUP2]      = 0x00b2,  // ²
    [SUP3]      = 0x00b3,  // ³
    [SUP4]      = 0x00b4,  // ⁴
    [HELLP]     = 0x2026,  // …
    [EMPTY_SET] = 0x00D8,  // Ø
    [SGR]       = 0x203A,  // ›
    [SGL]       = 0x2039,  // ‹
    [POUND]     = 0x00A3,  // £
    [EUR]       = 0x20AC,  // €
    [DGR]       = 0x00BB,  // »
    [DGL]       = 0x00AB,  // «
    [CENT]      = 0x00A2,  // ¢
    [DOLLAR]    = 0x0024,  // $
    [ARRL]      = 0x2190,  // ←
    [ARRR]      = 0x2192,  // →
    [ARRLR]     = 0x2194,  // ↔
    [DARRL]     = 0x21D0,  // ⇐
    [DARRR]     = 0x21D2,  // ⇒
    [DARRLR]    = 0x21D4,  // ⇔

    [CEDILLA] = 0x0327,  // ̧
    [MACRON]  = 0x0304,  // ̄
    [SLWQM]   = 0x201A,  // ‚
    [SLQM]    = 0x2018,  // ‘
    [SRQM]    = 0x2019,  // ’
    [EM_DASH] = 0x2014,  // —
    [CSHS]    = 0x1E9E,  // ẞ, capital sharp s
    [DLWQM]   = 0x201E,  // „
    [DLQM]    = 0x201C,  // “
    [DRQM]    = 0x201D,  // ”
    [EN_DASH] = 0x2013,  // –
    [WCIRCLE] = 0x25CB,  // ○
    [CHCKM]   = 0x2714,  // ✔
    [XSIGN]   = 0x00D7,  // ×
    [BULLET]  = 0x2022,  // •
    [MDOT]    = 0x00B7,  // ·
    [NNBS]    = 0x202f,  // Narrow no-break space

    /* NumPad layer */
    [COLON] = 0x003a,  // :
};
