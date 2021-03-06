/*
 * DistAIXPostprocessor.h
 * Postprocesses output file to fit DistAIX format
 */

#ifndef SRC_DISTAIXPOSTPROCESSOR_H_
#define SRC_DISTAIXPOSTPROCESSOR_H_

#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>


class DistAIXPostprocessor{
    
    public:
        DistAIXPostprocessor(std::string template_folder);
        virtual ~DistAIXPostprocessor();

        void postprocess(std::string output_file_name);

    private:
        void orderComponents(std::vector<std::string> component, std::string transformerId);
        void convertComponentIDs();
        
        void convertElGridIDs();
        void writeCSVFile(std::vector<std::vector<std::string> > dictionary);
        std::string convertInputFile(std::string output_file_name);
        void splitCSVFile(std::string filepath);
        void setDefaultParameters();
        
        std::string template_folder;

        std::vector<std::vector<std::string> > components;
        std::vector<std::vector<std::string> > el_grid;
        std::vector<std::vector<std::string> > componentsOrdered;
        std::vector<std::vector<std::string> > nonTopologyComponents;

        std::map<std::string, unsigned int> idConversionMap;
        std::map<std::string, std::string> defaultParameterConversionMap;

};

#endif