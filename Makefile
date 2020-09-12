
SRC_DIR := ./source
SRC_TEMP_DIR := ./source-temp
BIN_DIR := ./bin
TEST_DIR := ./test
TEST_TEMP_DIR := ./test-temp
ADAPTERS_DIR := ./adapters
HTML_DIR := ./html
WWW_DIR := ./www

# generate 32 bit code on 64 bit systems, disable gcc warnings
CC := gcc -m32 -w
AS := as --m32
LD := ld -m elf_i386

# choose between oracle jjs and nodejs 
JS := nodejs
JS_ADAPTER := nodejs_adapter.js
# JS := jjs -J-Xmx1g -J-Xss16m 
# JS_ADAPTER := oracle_jjs_adapter.js


BMINUS_CVIRTUALMACHINE_SRC := $(addprefix $(SRC_DIR)/, globals.h stringlib.h errormessages.h preprocessor.h token.h \
                                target_cvirtualmachine.h \
                                compiler.h syntax.h bminus.c)
                                
BMINUS_LINUXASSEMBLERX86_SRC := $(addprefix $(SRC_DIR)/, globals.h stringlib.h errormessages.h preprocessor.h token.h \
                                target_linuxassemblerx86.h \
                                compiler.h syntax.h bminus.c)

BMINUS_JAVASCRIPT_SRC := $(addprefix $(SRC_DIR)/, globals.h stringlib.h errormessages.h preprocessor.h token.h \
                                target_javascript.h \
                                compiler.h syntax.h bminus.c)

BMINUS_TEST_SRC:= $(sort $(wildcard $(TEST_DIR)/*.c))


all: work_dirs check_js bminus_cvirtualmachine bminus_linuxassemblerx86 bminus_javascript web_browser_compile regression_test self_compile_test

self_compile_test: check_js self_compile_test_cvirtualmachine self_compile_test_linuxassemblerx86 self_compile_test_javascript

work_dirs:
	mkdir -p $(SRC_TEMP_DIR) $(TEST_TEMP_DIR) $(BIN_DIR) $(WWW_DIR)  	

clean:
	rm -f $(SRC_TEMP_DIR)/* $(TEST_TEMP_DIR)/* $(BIN_DIR)/* $(WWW_DIR)/*

check_js:
	echo "Checking for javascript - will terminate if not found"
	which $(JS)

# bminus_cvirtualmachine
# ----------------------
#
bminus_cvirtualmachine: $(BIN_DIR)/bminus_cvirtualmachine

$(BIN_DIR)/bminus_cvirtualmachine: $(SRC_TEMP_DIR)/bminus_cvirtualmachine.c
	$(CC) -include $(SRC_DIR)/builtinfuncs_ansic.h -o $@ $^

$(SRC_TEMP_DIR)/bminus_cvirtualmachine.c: $(BMINUS_CVIRTUALMACHINE_SRC)
	cat $^ > $@


# bminus_linuxassemblerx86
# --------------
#
bminus_linuxassemblerx86: $(BIN_DIR)/bminus_linuxassemblerx86

$(BIN_DIR)/bminus_linuxassemblerx86: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86.c
	$(CC) -include $(SRC_DIR)/builtinfuncs_ansic.h -o $@ $^

$(SRC_TEMP_DIR)/bminus_linuxassemblerx86.c: $(BMINUS_LINUXASSEMBLERX86_SRC)
	cat $^ > $@


# bminus_javascript
# --------------
#
bminus_javascript: $(BIN_DIR)/bminus_javascript

$(BIN_DIR)/bminus_javascript: $(SRC_TEMP_DIR)/bminus_javascript.c
	$(CC) -include $(SRC_DIR)/builtinfuncs_ansic.h -o $@ $^

$(SRC_TEMP_DIR)/bminus_javascript.c: $(BMINUS_JAVASCRIPT_SRC)
	cat $^ > $@


# self_compile_test_cvirtualmachine
# ---------------------------------
#
self_compile_test_cvirtualmachine: $(SRC_TEMP_DIR)/bminus_cvirtualmachine_self.c $(SRC_TEMP_DIR)/bminus_cvirtualmachine_self_self.c 
	diff -q $^

$(SRC_TEMP_DIR)/bminus_cvirtualmachine_self.c: $(SRC_TEMP_DIR)/bminus_cvirtualmachine.c $(BIN_DIR)/bminus_cvirtualmachine
	$(BIN_DIR)/bminus_cvirtualmachine <$< >$@

$(SRC_TEMP_DIR)/bminus_cvirtualmachine_self_self.c: $(SRC_TEMP_DIR)/bminus_cvirtualmachine.c $(BIN_DIR)/bminus_cvirtualmachine_self
	$(BIN_DIR)/bminus_cvirtualmachine_self <$< >$@

$(BIN_DIR)/bminus_cvirtualmachine_self: $(SRC_TEMP_DIR)/bminus_cvirtualmachine_self.c
	$(CC) -o $@ $^


# self_compile_test_linuxassemblerx86
# -----------------------------------
#
self_compile_test_linuxassemblerx86: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self.asm $(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self_self.asm
	diff -q $^

$(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self.asm: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86.c $(BIN_DIR)/bminus_linuxassemblerx86
	$(BIN_DIR)/bminus_linuxassemblerx86 <$< >$@

$(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self_self.asm: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86.c $(BIN_DIR)/bminus_linuxassemblerx86_self
	$(BIN_DIR)/bminus_linuxassemblerx86_self <$< >$@

$(BIN_DIR)/bminus_linuxassemblerx86_self: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self.asm 
	$(AS) --gstabs+ -o $(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self.o $^
	$(LD) -o $@ $(SRC_TEMP_DIR)/bminus_linuxassemblerx86_self.o

	
# self_compile_test_javascript
# ----------------------------
#
self_compile_test_javascript: $(SRC_TEMP_DIR)/bminus_javascript_self.js $(SRC_TEMP_DIR)/bminus_javascript_self_self.js
	diff -q $^

$(SRC_TEMP_DIR)/bminus_javascript_self.js: $(SRC_TEMP_DIR)/bminus_javascript.c $(BIN_DIR)/bminus_javascript
	$(BIN_DIR)/bminus_javascript <$< >$@

$(SRC_TEMP_DIR)/bminus_javascript_self_self.js: $(SRC_TEMP_DIR)/bminus_javascript.c $(SRC_TEMP_DIR)/bminus_javascript_self.js
	cat $(SRC_TEMP_DIR)/bminus_javascript_self.js $(ADAPTERS_DIR)/$(JS_ADAPTER) >$(SRC_TEMP_DIR)/bminus_javascript_self_jjs.js
	$(JS) $(SRC_TEMP_DIR)/bminus_javascript_self_jjs.js <$< >$@


# web_browser_compile
# -------------------
#
WWW_HTML := $(WWW_DIR)/compile_in_browser_to_cvirtualmachine.html \
            $(WWW_DIR)/compile_in_browser_to_linuxassemblerx86.html \
            $(WWW_DIR)/compile_in_browser_to_javascript.html \

WWW_ADAPTERS := $(WWW_DIR)/web_browser_adapter.js

WWW_COMPILER_JAVASCRIPT_SRC := $(WWW_DIR)/bminus_cvirtualmachine.js $(WWW_DIR)/bminus_linuxassemblerx86.js $(WWW_DIR)/bminus_javascript.js

web_browser_compile: $(WWW_HTML) $(WWW_ADAPTERS) $(WWW_COMPILER_JAVASCRIPT_SRC)

$(WWW_HTML):
	cp $(HTML_DIR)/$(notdir $@) $@

$(WWW_ADAPTERS):
	cp $(ADAPTERS_DIR)/$(notdir $@) $@

$(WWW_DIR)/bminus_cvirtualmachine.js: $(SRC_TEMP_DIR)/bminus_cvirtualmachine.c $(BIN_DIR)/bminus_javascript
	$(BIN_DIR)/bminus_javascript <$< >$@

$(WWW_DIR)/bminus_linuxassemblerx86.js: $(SRC_TEMP_DIR)/bminus_linuxassemblerx86.c $(BIN_DIR)/bminus_javascript
	$(BIN_DIR)/bminus_javascript <$< >$@

$(WWW_DIR)/bminus_javascript.js: $(SRC_TEMP_DIR)/bminus_javascript.c $(BIN_DIR)/bminus_javascript
	$(BIN_DIR)/bminus_javascript <$< >$@


# regression_test
# ---------------
#
# 1. compile test with gcc, run test and save output
# 2. compile test with bminus (generate cvirtualmachine), run test and save output
# 3. compare output of 1. and 2.
# 4. compile test with bminus (generate x86 assembler), run test and save output
# 5. compare output of 1. and 4.
# 6. compile test with bminus (generate javascript), run test and save output
# 7. compare output of 1. and 6.
BMINUS_TEST_TARGET := $(patsubst %.c,%,$(BMINUS_TEST_SRC))

regression_test: $(BIN_DIR)/bminus_cvirtualmachine \
                 $(BIN_DIR)/bminus_linuxassemblerx86 \
                 $(BIN_DIR)/bminus_javascript \
                 $(BMINUS_TEST_TARGET)
				 

$(BMINUS_TEST_TARGET): % : %.c
	# 1.
	$(CC) -include $(SRC_DIR)/builtinfuncs_ansic.h -o $(TEST_TEMP_DIR)/$(notdir $@) $<
	-$(TEST_TEMP_DIR)/$(notdir $@) >$(TEST_TEMP_DIR)/$(notdir $@)_output.txt
	# 2.
	$(BIN_DIR)/bminus_cvirtualmachine <$< >$(TEST_TEMP_DIR)/$(notdir $@)_cvm.c
	$(CC) -o $(TEST_TEMP_DIR)/$(notdir $@)_cvm $(TEST_TEMP_DIR)/$(notdir $@)_cvm.c
	-$(TEST_TEMP_DIR)/$(notdir $@)_cvm >$(TEST_TEMP_DIR)/$(notdir $@)_cvm_output.txt
	# 3.
	diff $(TEST_TEMP_DIR)/$(notdir $@)_output.txt $(TEST_TEMP_DIR)/$(notdir $@)_cvm_output.txt
	# 4.
	$(BIN_DIR)/bminus_linuxassemblerx86 <$< >$(TEST_TEMP_DIR)/$(notdir $@)_x86.asm
	$(AS) --gstabs+ -o $(TEST_TEMP_DIR)/$(notdir $@)_x86.o $(TEST_TEMP_DIR)/$(notdir $@)_x86.asm
	$(LD) -o $(TEST_TEMP_DIR)/$(notdir $@)_x86 $(TEST_TEMP_DIR)/$(notdir $@)_x86.o
	-$(TEST_TEMP_DIR)/$(notdir $@)_x86 >$(TEST_TEMP_DIR)/$(notdir $@)_x86_output.txt
	# 5.
	diff $(TEST_TEMP_DIR)/$(notdir $@)_output.txt $(TEST_TEMP_DIR)/$(notdir $@)_x86_output.txt
	# 6.
	$(BIN_DIR)/bminus_javascript <$< >$(TEST_TEMP_DIR)/$(notdir $@)_jvm.js
	cat $(TEST_TEMP_DIR)/$(notdir $@)_jvm.js $(ADAPTERS_DIR)/$(JS_ADAPTER) >$(TEST_TEMP_DIR)/$(notdir $@)_jvm_jjs.js
	$(JS) $(TEST_TEMP_DIR)/$(notdir $@)_jvm_jjs.js >$(TEST_TEMP_DIR)/$(notdir $@)_jvm_jjs_output.txt
	# 7.
	diff $(TEST_TEMP_DIR)/$(notdir $@)_output.txt $(TEST_TEMP_DIR)/$(notdir $@)_jvm_jjs_output.txt
