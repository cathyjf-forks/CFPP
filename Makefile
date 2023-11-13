BUILD_DIR := .
OBJECT_DIR := $(BUILD_DIR)/Build/objects
LIB_DIR := $(BUILD_DIR)/Build/lib
SOURCE_DIR := CF++/source
OBJECTS := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJECT_DIR)/%.o, $(wildcard $(SOURCE_DIR)/*.cpp))
CPPFLAGS := -ICF++/include -std=c++20 -O3 -flto -Wall -Werror $(CPPFLAGS_EXTRA)
LIBTOOL := libtool

$(LIB_DIR)/libCF++.a : $(OBJECTS) | $(LIB_DIR)
	$(LIBTOOL) -static -o $@ $^

$(OBJECT_DIR)/%.o : $(SOURCE_DIR)/%.cpp | $(OBJECT_DIR)
	$(CXX) -c $^ -o $@ $(CPPFLAGS)

$(OBJECT_DIR) $(LIB_DIR) :
	mkdir -p $@

clean :
	rm -Rf $(OBJECT_DIR) $(LIB_DIR)

.PHONY : clean