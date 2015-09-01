FILE(REMOVE_RECURSE
  "../../../build_Linux/libMOTORINT.pdb"
  "../../../build_Linux/libMOTORINT.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/MOTORINT.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
