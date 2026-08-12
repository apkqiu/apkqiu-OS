#pragma once
// PyMake Auto Generated

#include "idt.h"
void idt_set_gate(int num, uint64_t handler, uint16_t selector, uint8_t flags);
void common_handler(int vector, IntFrame *frame, uint64_t error_code);
__attribute__((interrupt)) void idt_0(IntFrame *frame){common_handler(0, frame, 0);}
__attribute__((interrupt)) void idt_1(IntFrame *frame){common_handler(1, frame, 0);}
__attribute__((interrupt)) void idt_2(IntFrame *frame){common_handler(2, frame, 0);}
__attribute__((interrupt)) void idt_3(IntFrame *frame){common_handler(3, frame, 0);}
__attribute__((interrupt)) void idt_4(IntFrame *frame){common_handler(4, frame, 0);}
__attribute__((interrupt)) void idt_5(IntFrame *frame){common_handler(5, frame, 0);}
__attribute__((interrupt)) void idt_6(IntFrame *frame){common_handler(6, frame, 0);}
__attribute__((interrupt)) void idt_7(IntFrame *frame){common_handler(7, frame, 0);}
__attribute__((interrupt)) void idt_9(IntFrame *frame){common_handler(9, frame, 0);}
__attribute__((interrupt)) void idt_15(IntFrame *frame){common_handler(15, frame, 0);}
__attribute__((interrupt)) void idt_16(IntFrame *frame){common_handler(16, frame, 0);}
__attribute__((interrupt)) void idt_18(IntFrame *frame){common_handler(18, frame, 0);}
__attribute__((interrupt)) void idt_19(IntFrame *frame){common_handler(19, frame, 0);}
__attribute__((interrupt)) void idt_20(IntFrame *frame){common_handler(20, frame, 0);}
__attribute__((interrupt)) void idt_21(IntFrame *frame){common_handler(21, frame, 0);}
__attribute__((interrupt)) void idt_22(IntFrame *frame){common_handler(22, frame, 0);}
__attribute__((interrupt)) void idt_23(IntFrame *frame){common_handler(23, frame, 0);}
__attribute__((interrupt)) void idt_24(IntFrame *frame){common_handler(24, frame, 0);}
__attribute__((interrupt)) void idt_25(IntFrame *frame){common_handler(25, frame, 0);}
__attribute__((interrupt)) void idt_26(IntFrame *frame){common_handler(26, frame, 0);}
__attribute__((interrupt)) void idt_27(IntFrame *frame){common_handler(27, frame, 0);}
__attribute__((interrupt)) void idt_28(IntFrame *frame){common_handler(28, frame, 0);}
__attribute__((interrupt)) void idt_29(IntFrame *frame){common_handler(29, frame, 0);}
__attribute__((interrupt)) void idt_31(IntFrame *frame){common_handler(31, frame, 0);}
__attribute__((interrupt)) void idt_32(IntFrame *frame){common_handler(32, frame, 0);}
__attribute__((interrupt)) void idt_33(IntFrame *frame){common_handler(33, frame, 0);}
__attribute__((interrupt)) void idt_34(IntFrame *frame){common_handler(34, frame, 0);}
__attribute__((interrupt)) void idt_35(IntFrame *frame){common_handler(35, frame, 0);}
__attribute__((interrupt)) void idt_36(IntFrame *frame){common_handler(36, frame, 0);}
__attribute__((interrupt)) void idt_37(IntFrame *frame){common_handler(37, frame, 0);}
__attribute__((interrupt)) void idt_38(IntFrame *frame){common_handler(38, frame, 0);}
__attribute__((interrupt)) void idt_39(IntFrame *frame){common_handler(39, frame, 0);}
__attribute__((interrupt)) void idt_40(IntFrame *frame){common_handler(40, frame, 0);}
__attribute__((interrupt)) void idt_41(IntFrame *frame){common_handler(41, frame, 0);}
__attribute__((interrupt)) void idt_42(IntFrame *frame){common_handler(42, frame, 0);}
__attribute__((interrupt)) void idt_43(IntFrame *frame){common_handler(43, frame, 0);}
__attribute__((interrupt)) void idt_44(IntFrame *frame){common_handler(44, frame, 0);}
__attribute__((interrupt)) void idt_45(IntFrame *frame){common_handler(45, frame, 0);}
__attribute__((interrupt)) void idt_46(IntFrame *frame){common_handler(46, frame, 0);}
__attribute__((interrupt)) void idt_47(IntFrame *frame){common_handler(47, frame, 0);}
__attribute__((interrupt)) void idt_48(IntFrame *frame){common_handler(48, frame, 0);}
__attribute__((interrupt)) void idt_49(IntFrame *frame){common_handler(49, frame, 0);}
__attribute__((interrupt)) void idt_50(IntFrame *frame){common_handler(50, frame, 0);}
__attribute__((interrupt)) void idt_51(IntFrame *frame){common_handler(51, frame, 0);}
__attribute__((interrupt)) void idt_52(IntFrame *frame){common_handler(52, frame, 0);}
__attribute__((interrupt)) void idt_53(IntFrame *frame){common_handler(53, frame, 0);}
__attribute__((interrupt)) void idt_54(IntFrame *frame){common_handler(54, frame, 0);}
__attribute__((interrupt)) void idt_55(IntFrame *frame){common_handler(55, frame, 0);}
__attribute__((interrupt)) void idt_56(IntFrame *frame){common_handler(56, frame, 0);}
__attribute__((interrupt)) void idt_57(IntFrame *frame){common_handler(57, frame, 0);}
__attribute__((interrupt)) void idt_58(IntFrame *frame){common_handler(58, frame, 0);}
__attribute__((interrupt)) void idt_59(IntFrame *frame){common_handler(59, frame, 0);}
__attribute__((interrupt)) void idt_60(IntFrame *frame){common_handler(60, frame, 0);}
__attribute__((interrupt)) void idt_61(IntFrame *frame){common_handler(61, frame, 0);}
__attribute__((interrupt)) void idt_62(IntFrame *frame){common_handler(62, frame, 0);}
__attribute__((interrupt)) void idt_63(IntFrame *frame){common_handler(63, frame, 0);}
__attribute__((interrupt)) void idt_64(IntFrame *frame){common_handler(64, frame, 0);}
__attribute__((interrupt)) void idt_65(IntFrame *frame){common_handler(65, frame, 0);}
__attribute__((interrupt)) void idt_66(IntFrame *frame){common_handler(66, frame, 0);}
__attribute__((interrupt)) void idt_67(IntFrame *frame){common_handler(67, frame, 0);}
__attribute__((interrupt)) void idt_68(IntFrame *frame){common_handler(68, frame, 0);}
__attribute__((interrupt)) void idt_69(IntFrame *frame){common_handler(69, frame, 0);}
__attribute__((interrupt)) void idt_70(IntFrame *frame){common_handler(70, frame, 0);}
__attribute__((interrupt)) void idt_71(IntFrame *frame){common_handler(71, frame, 0);}
__attribute__((interrupt)) void idt_72(IntFrame *frame){common_handler(72, frame, 0);}
__attribute__((interrupt)) void idt_73(IntFrame *frame){common_handler(73, frame, 0);}
__attribute__((interrupt)) void idt_74(IntFrame *frame){common_handler(74, frame, 0);}
__attribute__((interrupt)) void idt_75(IntFrame *frame){common_handler(75, frame, 0);}
__attribute__((interrupt)) void idt_76(IntFrame *frame){common_handler(76, frame, 0);}
__attribute__((interrupt)) void idt_77(IntFrame *frame){common_handler(77, frame, 0);}
__attribute__((interrupt)) void idt_78(IntFrame *frame){common_handler(78, frame, 0);}
__attribute__((interrupt)) void idt_79(IntFrame *frame){common_handler(79, frame, 0);}
__attribute__((interrupt)) void idt_80(IntFrame *frame){common_handler(80, frame, 0);}
__attribute__((interrupt)) void idt_81(IntFrame *frame){common_handler(81, frame, 0);}
__attribute__((interrupt)) void idt_82(IntFrame *frame){common_handler(82, frame, 0);}
__attribute__((interrupt)) void idt_83(IntFrame *frame){common_handler(83, frame, 0);}
__attribute__((interrupt)) void idt_84(IntFrame *frame){common_handler(84, frame, 0);}
__attribute__((interrupt)) void idt_85(IntFrame *frame){common_handler(85, frame, 0);}
__attribute__((interrupt)) void idt_86(IntFrame *frame){common_handler(86, frame, 0);}
__attribute__((interrupt)) void idt_87(IntFrame *frame){common_handler(87, frame, 0);}
__attribute__((interrupt)) void idt_88(IntFrame *frame){common_handler(88, frame, 0);}
__attribute__((interrupt)) void idt_89(IntFrame *frame){common_handler(89, frame, 0);}
__attribute__((interrupt)) void idt_90(IntFrame *frame){common_handler(90, frame, 0);}
__attribute__((interrupt)) void idt_91(IntFrame *frame){common_handler(91, frame, 0);}
__attribute__((interrupt)) void idt_92(IntFrame *frame){common_handler(92, frame, 0);}
__attribute__((interrupt)) void idt_93(IntFrame *frame){common_handler(93, frame, 0);}
__attribute__((interrupt)) void idt_94(IntFrame *frame){common_handler(94, frame, 0);}
__attribute__((interrupt)) void idt_95(IntFrame *frame){common_handler(95, frame, 0);}
__attribute__((interrupt)) void idt_96(IntFrame *frame){common_handler(96, frame, 0);}
__attribute__((interrupt)) void idt_97(IntFrame *frame){common_handler(97, frame, 0);}
__attribute__((interrupt)) void idt_98(IntFrame *frame){common_handler(98, frame, 0);}
__attribute__((interrupt)) void idt_99(IntFrame *frame){common_handler(99, frame, 0);}
__attribute__((interrupt)) void idt_100(IntFrame *frame){common_handler(100, frame, 0);}
__attribute__((interrupt)) void idt_101(IntFrame *frame){common_handler(101, frame, 0);}
__attribute__((interrupt)) void idt_102(IntFrame *frame){common_handler(102, frame, 0);}
__attribute__((interrupt)) void idt_103(IntFrame *frame){common_handler(103, frame, 0);}
__attribute__((interrupt)) void idt_104(IntFrame *frame){common_handler(104, frame, 0);}
__attribute__((interrupt)) void idt_105(IntFrame *frame){common_handler(105, frame, 0);}
__attribute__((interrupt)) void idt_106(IntFrame *frame){common_handler(106, frame, 0);}
__attribute__((interrupt)) void idt_107(IntFrame *frame){common_handler(107, frame, 0);}
__attribute__((interrupt)) void idt_108(IntFrame *frame){common_handler(108, frame, 0);}
__attribute__((interrupt)) void idt_109(IntFrame *frame){common_handler(109, frame, 0);}
__attribute__((interrupt)) void idt_110(IntFrame *frame){common_handler(110, frame, 0);}
__attribute__((interrupt)) void idt_111(IntFrame *frame){common_handler(111, frame, 0);}
__attribute__((interrupt)) void idt_112(IntFrame *frame){common_handler(112, frame, 0);}
__attribute__((interrupt)) void idt_113(IntFrame *frame){common_handler(113, frame, 0);}
__attribute__((interrupt)) void idt_114(IntFrame *frame){common_handler(114, frame, 0);}
__attribute__((interrupt)) void idt_115(IntFrame *frame){common_handler(115, frame, 0);}
__attribute__((interrupt)) void idt_116(IntFrame *frame){common_handler(116, frame, 0);}
__attribute__((interrupt)) void idt_117(IntFrame *frame){common_handler(117, frame, 0);}
__attribute__((interrupt)) void idt_118(IntFrame *frame){common_handler(118, frame, 0);}
__attribute__((interrupt)) void idt_119(IntFrame *frame){common_handler(119, frame, 0);}
__attribute__((interrupt)) void idt_120(IntFrame *frame){common_handler(120, frame, 0);}
__attribute__((interrupt)) void idt_121(IntFrame *frame){common_handler(121, frame, 0);}
__attribute__((interrupt)) void idt_122(IntFrame *frame){common_handler(122, frame, 0);}
__attribute__((interrupt)) void idt_123(IntFrame *frame){common_handler(123, frame, 0);}
__attribute__((interrupt)) void idt_124(IntFrame *frame){common_handler(124, frame, 0);}
__attribute__((interrupt)) void idt_125(IntFrame *frame){common_handler(125, frame, 0);}
__attribute__((interrupt)) void idt_126(IntFrame *frame){common_handler(126, frame, 0);}
__attribute__((interrupt)) void idt_127(IntFrame *frame){common_handler(127, frame, 0);}
__attribute__((interrupt)) void idt_128(IntFrame *frame){common_handler(128, frame, 0);}
__attribute__((interrupt)) void idt_129(IntFrame *frame){common_handler(129, frame, 0);}
__attribute__((interrupt)) void idt_130(IntFrame *frame){common_handler(130, frame, 0);}
__attribute__((interrupt)) void idt_131(IntFrame *frame){common_handler(131, frame, 0);}
__attribute__((interrupt)) void idt_132(IntFrame *frame){common_handler(132, frame, 0);}
__attribute__((interrupt)) void idt_133(IntFrame *frame){common_handler(133, frame, 0);}
__attribute__((interrupt)) void idt_134(IntFrame *frame){common_handler(134, frame, 0);}
__attribute__((interrupt)) void idt_135(IntFrame *frame){common_handler(135, frame, 0);}
__attribute__((interrupt)) void idt_136(IntFrame *frame){common_handler(136, frame, 0);}
__attribute__((interrupt)) void idt_137(IntFrame *frame){common_handler(137, frame, 0);}
__attribute__((interrupt)) void idt_138(IntFrame *frame){common_handler(138, frame, 0);}
__attribute__((interrupt)) void idt_139(IntFrame *frame){common_handler(139, frame, 0);}
__attribute__((interrupt)) void idt_140(IntFrame *frame){common_handler(140, frame, 0);}
__attribute__((interrupt)) void idt_141(IntFrame *frame){common_handler(141, frame, 0);}
__attribute__((interrupt)) void idt_142(IntFrame *frame){common_handler(142, frame, 0);}
__attribute__((interrupt)) void idt_143(IntFrame *frame){common_handler(143, frame, 0);}
__attribute__((interrupt)) void idt_144(IntFrame *frame){common_handler(144, frame, 0);}
__attribute__((interrupt)) void idt_145(IntFrame *frame){common_handler(145, frame, 0);}
__attribute__((interrupt)) void idt_146(IntFrame *frame){common_handler(146, frame, 0);}
__attribute__((interrupt)) void idt_147(IntFrame *frame){common_handler(147, frame, 0);}
__attribute__((interrupt)) void idt_148(IntFrame *frame){common_handler(148, frame, 0);}
__attribute__((interrupt)) void idt_149(IntFrame *frame){common_handler(149, frame, 0);}
__attribute__((interrupt)) void idt_150(IntFrame *frame){common_handler(150, frame, 0);}
__attribute__((interrupt)) void idt_151(IntFrame *frame){common_handler(151, frame, 0);}
__attribute__((interrupt)) void idt_152(IntFrame *frame){common_handler(152, frame, 0);}
__attribute__((interrupt)) void idt_153(IntFrame *frame){common_handler(153, frame, 0);}
__attribute__((interrupt)) void idt_154(IntFrame *frame){common_handler(154, frame, 0);}
__attribute__((interrupt)) void idt_155(IntFrame *frame){common_handler(155, frame, 0);}
__attribute__((interrupt)) void idt_156(IntFrame *frame){common_handler(156, frame, 0);}
__attribute__((interrupt)) void idt_157(IntFrame *frame){common_handler(157, frame, 0);}
__attribute__((interrupt)) void idt_158(IntFrame *frame){common_handler(158, frame, 0);}
__attribute__((interrupt)) void idt_159(IntFrame *frame){common_handler(159, frame, 0);}
__attribute__((interrupt)) void idt_160(IntFrame *frame){common_handler(160, frame, 0);}
__attribute__((interrupt)) void idt_161(IntFrame *frame){common_handler(161, frame, 0);}
__attribute__((interrupt)) void idt_162(IntFrame *frame){common_handler(162, frame, 0);}
__attribute__((interrupt)) void idt_163(IntFrame *frame){common_handler(163, frame, 0);}
__attribute__((interrupt)) void idt_164(IntFrame *frame){common_handler(164, frame, 0);}
__attribute__((interrupt)) void idt_165(IntFrame *frame){common_handler(165, frame, 0);}
__attribute__((interrupt)) void idt_166(IntFrame *frame){common_handler(166, frame, 0);}
__attribute__((interrupt)) void idt_167(IntFrame *frame){common_handler(167, frame, 0);}
__attribute__((interrupt)) void idt_168(IntFrame *frame){common_handler(168, frame, 0);}
__attribute__((interrupt)) void idt_169(IntFrame *frame){common_handler(169, frame, 0);}
__attribute__((interrupt)) void idt_170(IntFrame *frame){common_handler(170, frame, 0);}
__attribute__((interrupt)) void idt_171(IntFrame *frame){common_handler(171, frame, 0);}
__attribute__((interrupt)) void idt_172(IntFrame *frame){common_handler(172, frame, 0);}
__attribute__((interrupt)) void idt_173(IntFrame *frame){common_handler(173, frame, 0);}
__attribute__((interrupt)) void idt_174(IntFrame *frame){common_handler(174, frame, 0);}
__attribute__((interrupt)) void idt_175(IntFrame *frame){common_handler(175, frame, 0);}
__attribute__((interrupt)) void idt_176(IntFrame *frame){common_handler(176, frame, 0);}
__attribute__((interrupt)) void idt_177(IntFrame *frame){common_handler(177, frame, 0);}
__attribute__((interrupt)) void idt_178(IntFrame *frame){common_handler(178, frame, 0);}
__attribute__((interrupt)) void idt_179(IntFrame *frame){common_handler(179, frame, 0);}
__attribute__((interrupt)) void idt_180(IntFrame *frame){common_handler(180, frame, 0);}
__attribute__((interrupt)) void idt_181(IntFrame *frame){common_handler(181, frame, 0);}
__attribute__((interrupt)) void idt_182(IntFrame *frame){common_handler(182, frame, 0);}
__attribute__((interrupt)) void idt_183(IntFrame *frame){common_handler(183, frame, 0);}
__attribute__((interrupt)) void idt_184(IntFrame *frame){common_handler(184, frame, 0);}
__attribute__((interrupt)) void idt_185(IntFrame *frame){common_handler(185, frame, 0);}
__attribute__((interrupt)) void idt_186(IntFrame *frame){common_handler(186, frame, 0);}
__attribute__((interrupt)) void idt_187(IntFrame *frame){common_handler(187, frame, 0);}
__attribute__((interrupt)) void idt_188(IntFrame *frame){common_handler(188, frame, 0);}
__attribute__((interrupt)) void idt_189(IntFrame *frame){common_handler(189, frame, 0);}
__attribute__((interrupt)) void idt_190(IntFrame *frame){common_handler(190, frame, 0);}
__attribute__((interrupt)) void idt_191(IntFrame *frame){common_handler(191, frame, 0);}
__attribute__((interrupt)) void idt_192(IntFrame *frame){common_handler(192, frame, 0);}
__attribute__((interrupt)) void idt_193(IntFrame *frame){common_handler(193, frame, 0);}
__attribute__((interrupt)) void idt_194(IntFrame *frame){common_handler(194, frame, 0);}
__attribute__((interrupt)) void idt_195(IntFrame *frame){common_handler(195, frame, 0);}
__attribute__((interrupt)) void idt_196(IntFrame *frame){common_handler(196, frame, 0);}
__attribute__((interrupt)) void idt_197(IntFrame *frame){common_handler(197, frame, 0);}
__attribute__((interrupt)) void idt_198(IntFrame *frame){common_handler(198, frame, 0);}
__attribute__((interrupt)) void idt_199(IntFrame *frame){common_handler(199, frame, 0);}
__attribute__((interrupt)) void idt_200(IntFrame *frame){common_handler(200, frame, 0);}
__attribute__((interrupt)) void idt_201(IntFrame *frame){common_handler(201, frame, 0);}
__attribute__((interrupt)) void idt_202(IntFrame *frame){common_handler(202, frame, 0);}
__attribute__((interrupt)) void idt_203(IntFrame *frame){common_handler(203, frame, 0);}
__attribute__((interrupt)) void idt_204(IntFrame *frame){common_handler(204, frame, 0);}
__attribute__((interrupt)) void idt_205(IntFrame *frame){common_handler(205, frame, 0);}
__attribute__((interrupt)) void idt_206(IntFrame *frame){common_handler(206, frame, 0);}
__attribute__((interrupt)) void idt_207(IntFrame *frame){common_handler(207, frame, 0);}
__attribute__((interrupt)) void idt_208(IntFrame *frame){common_handler(208, frame, 0);}
__attribute__((interrupt)) void idt_209(IntFrame *frame){common_handler(209, frame, 0);}
__attribute__((interrupt)) void idt_210(IntFrame *frame){common_handler(210, frame, 0);}
__attribute__((interrupt)) void idt_211(IntFrame *frame){common_handler(211, frame, 0);}
__attribute__((interrupt)) void idt_212(IntFrame *frame){common_handler(212, frame, 0);}
__attribute__((interrupt)) void idt_213(IntFrame *frame){common_handler(213, frame, 0);}
__attribute__((interrupt)) void idt_214(IntFrame *frame){common_handler(214, frame, 0);}
__attribute__((interrupt)) void idt_215(IntFrame *frame){common_handler(215, frame, 0);}
__attribute__((interrupt)) void idt_216(IntFrame *frame){common_handler(216, frame, 0);}
__attribute__((interrupt)) void idt_217(IntFrame *frame){common_handler(217, frame, 0);}
__attribute__((interrupt)) void idt_218(IntFrame *frame){common_handler(218, frame, 0);}
__attribute__((interrupt)) void idt_219(IntFrame *frame){common_handler(219, frame, 0);}
__attribute__((interrupt)) void idt_220(IntFrame *frame){common_handler(220, frame, 0);}
__attribute__((interrupt)) void idt_221(IntFrame *frame){common_handler(221, frame, 0);}
__attribute__((interrupt)) void idt_222(IntFrame *frame){common_handler(222, frame, 0);}
__attribute__((interrupt)) void idt_223(IntFrame *frame){common_handler(223, frame, 0);}
__attribute__((interrupt)) void idt_224(IntFrame *frame){common_handler(224, frame, 0);}
__attribute__((interrupt)) void idt_225(IntFrame *frame){common_handler(225, frame, 0);}
__attribute__((interrupt)) void idt_226(IntFrame *frame){common_handler(226, frame, 0);}
__attribute__((interrupt)) void idt_227(IntFrame *frame){common_handler(227, frame, 0);}
__attribute__((interrupt)) void idt_228(IntFrame *frame){common_handler(228, frame, 0);}
__attribute__((interrupt)) void idt_229(IntFrame *frame){common_handler(229, frame, 0);}
__attribute__((interrupt)) void idt_230(IntFrame *frame){common_handler(230, frame, 0);}
__attribute__((interrupt)) void idt_231(IntFrame *frame){common_handler(231, frame, 0);}
__attribute__((interrupt)) void idt_232(IntFrame *frame){common_handler(232, frame, 0);}
__attribute__((interrupt)) void idt_233(IntFrame *frame){common_handler(233, frame, 0);}
__attribute__((interrupt)) void idt_234(IntFrame *frame){common_handler(234, frame, 0);}
__attribute__((interrupt)) void idt_235(IntFrame *frame){common_handler(235, frame, 0);}
__attribute__((interrupt)) void idt_236(IntFrame *frame){common_handler(236, frame, 0);}
__attribute__((interrupt)) void idt_237(IntFrame *frame){common_handler(237, frame, 0);}
__attribute__((interrupt)) void idt_238(IntFrame *frame){common_handler(238, frame, 0);}
__attribute__((interrupt)) void idt_239(IntFrame *frame){common_handler(239, frame, 0);}
__attribute__((interrupt)) void idt_240(IntFrame *frame){common_handler(240, frame, 0);}
__attribute__((interrupt)) void idt_241(IntFrame *frame){common_handler(241, frame, 0);}
__attribute__((interrupt)) void idt_242(IntFrame *frame){common_handler(242, frame, 0);}
__attribute__((interrupt)) void idt_243(IntFrame *frame){common_handler(243, frame, 0);}
__attribute__((interrupt)) void idt_244(IntFrame *frame){common_handler(244, frame, 0);}
__attribute__((interrupt)) void idt_245(IntFrame *frame){common_handler(245, frame, 0);}
__attribute__((interrupt)) void idt_246(IntFrame *frame){common_handler(246, frame, 0);}
__attribute__((interrupt)) void idt_247(IntFrame *frame){common_handler(247, frame, 0);}
__attribute__((interrupt)) void idt_248(IntFrame *frame){common_handler(248, frame, 0);}
__attribute__((interrupt)) void idt_249(IntFrame *frame){common_handler(249, frame, 0);}
__attribute__((interrupt)) void idt_250(IntFrame *frame){common_handler(250, frame, 0);}
__attribute__((interrupt)) void idt_251(IntFrame *frame){common_handler(251, frame, 0);}
__attribute__((interrupt)) void idt_252(IntFrame *frame){common_handler(252, frame, 0);}
__attribute__((interrupt)) void idt_253(IntFrame *frame){common_handler(253, frame, 0);}
__attribute__((interrupt)) void idt_254(IntFrame *frame){common_handler(254, frame, 0);}
__attribute__((interrupt)) void idt_255(IntFrame *frame){common_handler(255, frame, 0);}
__attribute__((interrupt)) void idt_8(IntFrame *frame, uint64_t error){common_handler(8, frame, error);}
__attribute__((interrupt)) void idt_10(IntFrame *frame, uint64_t error){common_handler(10, frame, error);}
__attribute__((interrupt)) void idt_11(IntFrame *frame, uint64_t error){common_handler(11, frame, error);}
__attribute__((interrupt)) void idt_12(IntFrame *frame, uint64_t error){common_handler(12, frame, error);}
__attribute__((interrupt)) void idt_13(IntFrame *frame, uint64_t error){common_handler(13, frame, error);}
__attribute__((interrupt)) void idt_14(IntFrame *frame, uint64_t error){common_handler(14, frame, error);}
__attribute__((interrupt)) void idt_17(IntFrame *frame, uint64_t error){common_handler(17, frame, error);}
__attribute__((interrupt)) void idt_30(IntFrame *frame, uint64_t error){common_handler(30, frame, error);}

void make_idt(){
    uint16_t cs = 0x18;
    asm volatile("mov %%cs, %0" : "=r"(cs));
/**/idt_set_gate(0, (uint64_t)idt_0, cs, 142);
/**/idt_set_gate(1, (uint64_t)idt_1, cs, 142);
/**/idt_set_gate(2, (uint64_t)idt_2, cs, 142);
/**/idt_set_gate(3, (uint64_t)idt_3, cs, 142);
/**/idt_set_gate(4, (uint64_t)idt_4, cs, 142);
/**/idt_set_gate(5, (uint64_t)idt_5, cs, 142);
/**/idt_set_gate(6, (uint64_t)idt_6, cs, 142);
/**/idt_set_gate(7, (uint64_t)idt_7, cs, 142);
/**/idt_set_gate(8, (uint64_t)idt_8, cs, 142);
/**/idt_set_gate(9, (uint64_t)idt_9, cs, 142);
/**/idt_set_gate(10, (uint64_t)idt_10, cs, 142);
/**/idt_set_gate(11, (uint64_t)idt_11, cs, 142);
/**/idt_set_gate(12, (uint64_t)idt_12, cs, 142);
/**/idt_set_gate(13, (uint64_t)idt_13, cs, 142);
/**/idt_set_gate(14, (uint64_t)idt_14, cs, 142);
/**/idt_set_gate(15, (uint64_t)idt_15, cs, 142);
/**/idt_set_gate(16, (uint64_t)idt_16, cs, 142);
/**/idt_set_gate(17, (uint64_t)idt_17, cs, 142);
/**/idt_set_gate(18, (uint64_t)idt_18, cs, 142);
/**/idt_set_gate(19, (uint64_t)idt_19, cs, 142);
/**/idt_set_gate(20, (uint64_t)idt_20, cs, 142);
/**/idt_set_gate(21, (uint64_t)idt_21, cs, 142);
/**/idt_set_gate(22, (uint64_t)idt_22, cs, 142);
/**/idt_set_gate(23, (uint64_t)idt_23, cs, 142);
/**/idt_set_gate(24, (uint64_t)idt_24, cs, 142);
/**/idt_set_gate(25, (uint64_t)idt_25, cs, 142);
/**/idt_set_gate(26, (uint64_t)idt_26, cs, 142);
/**/idt_set_gate(27, (uint64_t)idt_27, cs, 142);
/**/idt_set_gate(28, (uint64_t)idt_28, cs, 142);
/**/idt_set_gate(29, (uint64_t)idt_29, cs, 142);
/**/idt_set_gate(30, (uint64_t)idt_30, cs, 142);
/**/idt_set_gate(31, (uint64_t)idt_31, cs, 142);
/**/idt_set_gate(32, (uint64_t)idt_32, cs, 142);
/**/idt_set_gate(33, (uint64_t)idt_33, cs, 142);
/**/idt_set_gate(34, (uint64_t)idt_34, cs, 142);
/**/idt_set_gate(35, (uint64_t)idt_35, cs, 142);
/**/idt_set_gate(36, (uint64_t)idt_36, cs, 142);
/**/idt_set_gate(37, (uint64_t)idt_37, cs, 142);
/**/idt_set_gate(38, (uint64_t)idt_38, cs, 142);
/**/idt_set_gate(39, (uint64_t)idt_39, cs, 142);
/**/idt_set_gate(40, (uint64_t)idt_40, cs, 142);
/**/idt_set_gate(41, (uint64_t)idt_41, cs, 142);
/**/idt_set_gate(42, (uint64_t)idt_42, cs, 142);
/**/idt_set_gate(43, (uint64_t)idt_43, cs, 142);
/**/idt_set_gate(44, (uint64_t)idt_44, cs, 142);
/**/idt_set_gate(45, (uint64_t)idt_45, cs, 142);
/**/idt_set_gate(46, (uint64_t)idt_46, cs, 142);
/**/idt_set_gate(47, (uint64_t)idt_47, cs, 142);
/**/idt_set_gate(48, (uint64_t)idt_48, cs, 142);
/**/idt_set_gate(49, (uint64_t)idt_49, cs, 142);
/**/idt_set_gate(50, (uint64_t)idt_50, cs, 142);
/**/idt_set_gate(51, (uint64_t)idt_51, cs, 142);
/**/idt_set_gate(52, (uint64_t)idt_52, cs, 142);
/**/idt_set_gate(53, (uint64_t)idt_53, cs, 142);
/**/idt_set_gate(54, (uint64_t)idt_54, cs, 142);
/**/idt_set_gate(55, (uint64_t)idt_55, cs, 142);
/**/idt_set_gate(56, (uint64_t)idt_56, cs, 142);
/**/idt_set_gate(57, (uint64_t)idt_57, cs, 142);
/**/idt_set_gate(58, (uint64_t)idt_58, cs, 142);
/**/idt_set_gate(59, (uint64_t)idt_59, cs, 142);
/**/idt_set_gate(60, (uint64_t)idt_60, cs, 142);
/**/idt_set_gate(61, (uint64_t)idt_61, cs, 142);
/**/idt_set_gate(62, (uint64_t)idt_62, cs, 142);
/**/idt_set_gate(63, (uint64_t)idt_63, cs, 142);
/**/idt_set_gate(64, (uint64_t)idt_64, cs, 142);
/**/idt_set_gate(65, (uint64_t)idt_65, cs, 142);
/**/idt_set_gate(66, (uint64_t)idt_66, cs, 142);
/**/idt_set_gate(67, (uint64_t)idt_67, cs, 142);
/**/idt_set_gate(68, (uint64_t)idt_68, cs, 142);
/**/idt_set_gate(69, (uint64_t)idt_69, cs, 142);
/**/idt_set_gate(70, (uint64_t)idt_70, cs, 142);
/**/idt_set_gate(71, (uint64_t)idt_71, cs, 142);
/**/idt_set_gate(72, (uint64_t)idt_72, cs, 142);
/**/idt_set_gate(73, (uint64_t)idt_73, cs, 142);
/**/idt_set_gate(74, (uint64_t)idt_74, cs, 142);
/**/idt_set_gate(75, (uint64_t)idt_75, cs, 142);
/**/idt_set_gate(76, (uint64_t)idt_76, cs, 142);
/**/idt_set_gate(77, (uint64_t)idt_77, cs, 142);
/**/idt_set_gate(78, (uint64_t)idt_78, cs, 142);
/**/idt_set_gate(79, (uint64_t)idt_79, cs, 142);
/**/idt_set_gate(80, (uint64_t)idt_80, cs, 142);
/**/idt_set_gate(81, (uint64_t)idt_81, cs, 142);
/**/idt_set_gate(82, (uint64_t)idt_82, cs, 142);
/**/idt_set_gate(83, (uint64_t)idt_83, cs, 142);
/**/idt_set_gate(84, (uint64_t)idt_84, cs, 142);
/**/idt_set_gate(85, (uint64_t)idt_85, cs, 142);
/**/idt_set_gate(86, (uint64_t)idt_86, cs, 142);
/**/idt_set_gate(87, (uint64_t)idt_87, cs, 142);
/**/idt_set_gate(88, (uint64_t)idt_88, cs, 142);
/**/idt_set_gate(89, (uint64_t)idt_89, cs, 142);
/**/idt_set_gate(90, (uint64_t)idt_90, cs, 142);
/**/idt_set_gate(91, (uint64_t)idt_91, cs, 142);
/**/idt_set_gate(92, (uint64_t)idt_92, cs, 142);
/**/idt_set_gate(93, (uint64_t)idt_93, cs, 142);
/**/idt_set_gate(94, (uint64_t)idt_94, cs, 142);
/**/idt_set_gate(95, (uint64_t)idt_95, cs, 142);
/**/idt_set_gate(96, (uint64_t)idt_96, cs, 142);
/**/idt_set_gate(97, (uint64_t)idt_97, cs, 142);
/**/idt_set_gate(98, (uint64_t)idt_98, cs, 142);
/**/idt_set_gate(99, (uint64_t)idt_99, cs, 142);
/**/idt_set_gate(100, (uint64_t)idt_100, cs, 142);
/**/idt_set_gate(101, (uint64_t)idt_101, cs, 142);
/**/idt_set_gate(102, (uint64_t)idt_102, cs, 142);
/**/idt_set_gate(103, (uint64_t)idt_103, cs, 142);
/**/idt_set_gate(104, (uint64_t)idt_104, cs, 142);
/**/idt_set_gate(105, (uint64_t)idt_105, cs, 142);
/**/idt_set_gate(106, (uint64_t)idt_106, cs, 142);
/**/idt_set_gate(107, (uint64_t)idt_107, cs, 142);
/**/idt_set_gate(108, (uint64_t)idt_108, cs, 142);
/**/idt_set_gate(109, (uint64_t)idt_109, cs, 142);
/**/idt_set_gate(110, (uint64_t)idt_110, cs, 142);
/**/idt_set_gate(111, (uint64_t)idt_111, cs, 142);
/**/idt_set_gate(112, (uint64_t)idt_112, cs, 142);
/**/idt_set_gate(113, (uint64_t)idt_113, cs, 142);
/**/idt_set_gate(114, (uint64_t)idt_114, cs, 142);
/**/idt_set_gate(115, (uint64_t)idt_115, cs, 142);
/**/idt_set_gate(116, (uint64_t)idt_116, cs, 142);
/**/idt_set_gate(117, (uint64_t)idt_117, cs, 142);
/**/idt_set_gate(118, (uint64_t)idt_118, cs, 142);
/**/idt_set_gate(119, (uint64_t)idt_119, cs, 142);
/**/idt_set_gate(120, (uint64_t)idt_120, cs, 142);
/**/idt_set_gate(121, (uint64_t)idt_121, cs, 142);
/**/idt_set_gate(122, (uint64_t)idt_122, cs, 142);
/**/idt_set_gate(123, (uint64_t)idt_123, cs, 142);
/**/idt_set_gate(124, (uint64_t)idt_124, cs, 142);
/**/idt_set_gate(125, (uint64_t)idt_125, cs, 142);
/**/idt_set_gate(126, (uint64_t)idt_126, cs, 142);
/**/idt_set_gate(127, (uint64_t)idt_127, cs, 142);
/**/idt_set_gate(128, (uint64_t)idt_128, cs, 142);
/**/idt_set_gate(129, (uint64_t)idt_129, cs, 142);
/**/idt_set_gate(130, (uint64_t)idt_130, cs, 142);
/**/idt_set_gate(131, (uint64_t)idt_131, cs, 142);
/**/idt_set_gate(132, (uint64_t)idt_132, cs, 142);
/**/idt_set_gate(133, (uint64_t)idt_133, cs, 142);
/**/idt_set_gate(134, (uint64_t)idt_134, cs, 142);
/**/idt_set_gate(135, (uint64_t)idt_135, cs, 142);
/**/idt_set_gate(136, (uint64_t)idt_136, cs, 142);
/**/idt_set_gate(137, (uint64_t)idt_137, cs, 142);
/**/idt_set_gate(138, (uint64_t)idt_138, cs, 142);
/**/idt_set_gate(139, (uint64_t)idt_139, cs, 142);
/**/idt_set_gate(140, (uint64_t)idt_140, cs, 142);
/**/idt_set_gate(141, (uint64_t)idt_141, cs, 142);
/**/idt_set_gate(142, (uint64_t)idt_142, cs, 142);
/**/idt_set_gate(143, (uint64_t)idt_143, cs, 142);
/**/idt_set_gate(144, (uint64_t)idt_144, cs, 142);
/**/idt_set_gate(145, (uint64_t)idt_145, cs, 142);
/**/idt_set_gate(146, (uint64_t)idt_146, cs, 142);
/**/idt_set_gate(147, (uint64_t)idt_147, cs, 142);
/**/idt_set_gate(148, (uint64_t)idt_148, cs, 142);
/**/idt_set_gate(149, (uint64_t)idt_149, cs, 142);
/**/idt_set_gate(150, (uint64_t)idt_150, cs, 142);
/**/idt_set_gate(151, (uint64_t)idt_151, cs, 142);
/**/idt_set_gate(152, (uint64_t)idt_152, cs, 142);
/**/idt_set_gate(153, (uint64_t)idt_153, cs, 142);
/**/idt_set_gate(154, (uint64_t)idt_154, cs, 142);
/**/idt_set_gate(155, (uint64_t)idt_155, cs, 142);
/**/idt_set_gate(156, (uint64_t)idt_156, cs, 142);
/**/idt_set_gate(157, (uint64_t)idt_157, cs, 142);
/**/idt_set_gate(158, (uint64_t)idt_158, cs, 142);
/**/idt_set_gate(159, (uint64_t)idt_159, cs, 142);
/**/idt_set_gate(160, (uint64_t)idt_160, cs, 142);
/**/idt_set_gate(161, (uint64_t)idt_161, cs, 142);
/**/idt_set_gate(162, (uint64_t)idt_162, cs, 142);
/**/idt_set_gate(163, (uint64_t)idt_163, cs, 142);
/**/idt_set_gate(164, (uint64_t)idt_164, cs, 142);
/**/idt_set_gate(165, (uint64_t)idt_165, cs, 142);
/**/idt_set_gate(166, (uint64_t)idt_166, cs, 142);
/**/idt_set_gate(167, (uint64_t)idt_167, cs, 142);
/**/idt_set_gate(168, (uint64_t)idt_168, cs, 142);
/**/idt_set_gate(169, (uint64_t)idt_169, cs, 142);
/**/idt_set_gate(170, (uint64_t)idt_170, cs, 142);
/**/idt_set_gate(171, (uint64_t)idt_171, cs, 142);
/**/idt_set_gate(172, (uint64_t)idt_172, cs, 142);
/**/idt_set_gate(173, (uint64_t)idt_173, cs, 142);
/**/idt_set_gate(174, (uint64_t)idt_174, cs, 142);
/**/idt_set_gate(175, (uint64_t)idt_175, cs, 142);
/**/idt_set_gate(176, (uint64_t)idt_176, cs, 142);
/**/idt_set_gate(177, (uint64_t)idt_177, cs, 142);
/**/idt_set_gate(178, (uint64_t)idt_178, cs, 142);
/**/idt_set_gate(179, (uint64_t)idt_179, cs, 142);
/**/idt_set_gate(180, (uint64_t)idt_180, cs, 142);
/**/idt_set_gate(181, (uint64_t)idt_181, cs, 142);
/**/idt_set_gate(182, (uint64_t)idt_182, cs, 142);
/**/idt_set_gate(183, (uint64_t)idt_183, cs, 142);
/**/idt_set_gate(184, (uint64_t)idt_184, cs, 142);
/**/idt_set_gate(185, (uint64_t)idt_185, cs, 142);
/**/idt_set_gate(186, (uint64_t)idt_186, cs, 142);
/**/idt_set_gate(187, (uint64_t)idt_187, cs, 142);
/**/idt_set_gate(188, (uint64_t)idt_188, cs, 142);
/**/idt_set_gate(189, (uint64_t)idt_189, cs, 142);
/**/idt_set_gate(190, (uint64_t)idt_190, cs, 142);
/**/idt_set_gate(191, (uint64_t)idt_191, cs, 142);
/**/idt_set_gate(192, (uint64_t)idt_192, cs, 142);
/**/idt_set_gate(193, (uint64_t)idt_193, cs, 142);
/**/idt_set_gate(194, (uint64_t)idt_194, cs, 142);
/**/idt_set_gate(195, (uint64_t)idt_195, cs, 142);
/**/idt_set_gate(196, (uint64_t)idt_196, cs, 142);
/**/idt_set_gate(197, (uint64_t)idt_197, cs, 142);
/**/idt_set_gate(198, (uint64_t)idt_198, cs, 142);
/**/idt_set_gate(199, (uint64_t)idt_199, cs, 142);
/**/idt_set_gate(200, (uint64_t)idt_200, cs, 142);
/**/idt_set_gate(201, (uint64_t)idt_201, cs, 142);
/**/idt_set_gate(202, (uint64_t)idt_202, cs, 142);
/**/idt_set_gate(203, (uint64_t)idt_203, cs, 142);
/**/idt_set_gate(204, (uint64_t)idt_204, cs, 142);
/**/idt_set_gate(205, (uint64_t)idt_205, cs, 142);
/**/idt_set_gate(206, (uint64_t)idt_206, cs, 142);
/**/idt_set_gate(207, (uint64_t)idt_207, cs, 142);
/**/idt_set_gate(208, (uint64_t)idt_208, cs, 142);
/**/idt_set_gate(209, (uint64_t)idt_209, cs, 142);
/**/idt_set_gate(210, (uint64_t)idt_210, cs, 142);
/**/idt_set_gate(211, (uint64_t)idt_211, cs, 142);
/**/idt_set_gate(212, (uint64_t)idt_212, cs, 142);
/**/idt_set_gate(213, (uint64_t)idt_213, cs, 142);
/**/idt_set_gate(214, (uint64_t)idt_214, cs, 142);
/**/idt_set_gate(215, (uint64_t)idt_215, cs, 142);
/**/idt_set_gate(216, (uint64_t)idt_216, cs, 142);
/**/idt_set_gate(217, (uint64_t)idt_217, cs, 142);
/**/idt_set_gate(218, (uint64_t)idt_218, cs, 142);
/**/idt_set_gate(219, (uint64_t)idt_219, cs, 142);
/**/idt_set_gate(220, (uint64_t)idt_220, cs, 142);
/**/idt_set_gate(221, (uint64_t)idt_221, cs, 142);
/**/idt_set_gate(222, (uint64_t)idt_222, cs, 142);
/**/idt_set_gate(223, (uint64_t)idt_223, cs, 142);
/**/idt_set_gate(224, (uint64_t)idt_224, cs, 142);
/**/idt_set_gate(225, (uint64_t)idt_225, cs, 142);
/**/idt_set_gate(226, (uint64_t)idt_226, cs, 142);
/**/idt_set_gate(227, (uint64_t)idt_227, cs, 142);
/**/idt_set_gate(228, (uint64_t)idt_228, cs, 142);
/**/idt_set_gate(229, (uint64_t)idt_229, cs, 142);
/**/idt_set_gate(230, (uint64_t)idt_230, cs, 142);
/**/idt_set_gate(231, (uint64_t)idt_231, cs, 142);
/**/idt_set_gate(232, (uint64_t)idt_232, cs, 142);
/**/idt_set_gate(233, (uint64_t)idt_233, cs, 142);
/**/idt_set_gate(234, (uint64_t)idt_234, cs, 142);
/**/idt_set_gate(235, (uint64_t)idt_235, cs, 142);
/**/idt_set_gate(236, (uint64_t)idt_236, cs, 142);
/**/idt_set_gate(237, (uint64_t)idt_237, cs, 142);
/**/idt_set_gate(238, (uint64_t)idt_238, cs, 142);
/**/idt_set_gate(239, (uint64_t)idt_239, cs, 142);
/**/idt_set_gate(240, (uint64_t)idt_240, cs, 142);
/**/idt_set_gate(241, (uint64_t)idt_241, cs, 142);
/**/idt_set_gate(242, (uint64_t)idt_242, cs, 142);
/**/idt_set_gate(243, (uint64_t)idt_243, cs, 142);
/**/idt_set_gate(244, (uint64_t)idt_244, cs, 142);
/**/idt_set_gate(245, (uint64_t)idt_245, cs, 142);
/**/idt_set_gate(246, (uint64_t)idt_246, cs, 142);
/**/idt_set_gate(247, (uint64_t)idt_247, cs, 142);
/**/idt_set_gate(248, (uint64_t)idt_248, cs, 142);
/**/idt_set_gate(249, (uint64_t)idt_249, cs, 142);
/**/idt_set_gate(250, (uint64_t)idt_250, cs, 142);
/**/idt_set_gate(251, (uint64_t)idt_251, cs, 142);
/**/idt_set_gate(252, (uint64_t)idt_252, cs, 142);
/**/idt_set_gate(253, (uint64_t)idt_253, cs, 142);
/**/idt_set_gate(254, (uint64_t)idt_254, cs, 142);
/**/idt_set_gate(255, (uint64_t)idt_255, cs, 142);
}