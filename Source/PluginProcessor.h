/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

//Add the folliwng define and include in order to access math constants such as the number 'pi'
#define _USE_MATH_DEFINES
#include <math.h>
#include "Filter.hpp"


#include "../JuceLibraryCode/JuceHeader.h"

using namespace std;


//==============================================================================
/**
*/
class GraphicEqAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    GraphicEqAudioProcessor();
    ~GraphicEqAudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //==============================================================================
    // Declare bi-quad filter variables for each filter band/shelf
    
    //Sampling Rate
    float Fs;
    
    //Quality Factor for filters
    float Q = 1;
    
    //Input sample 'input'. Set input to the buffer.getReadPointer in the very beginning of each loop in order to work through the process using variables instead of buffers (input = buffer.getReadPointer(channel)[sample];)
    float input;
    
    float u1;  //Output of LSF, input to PKF1
    float u2;   //Output of PKF1, input to PKF2
    float u3;   //Output of PKF2, input to PKF3
    float u4;   //Output of PKF3, input to PKF4
    float u5;   //Output of PKF4, input to PKF5
    float u6;   //Output of PKF5, input to PKF6
    float u7;   //Output of PKF6, input to HSF
    float u8;   //Output of HSF, input to smoothing algorithm

    //Output sample 'output'. In the main process loop, after all processing has been done to x and your delay samples, assign y to the buffer.getWritePointer (i.e. buffer.getWritePointer(channel)[sample] = y;)
    float output;
    
    //dB Gain variable definitions for the slider objects. Pointer to the value of the actual gain slider on the GUI, referenced in the processor to determine the amp value to determine the [b,a] coefficeints
    /*
    AudioParameterFloat *LSFgain;
    AudioParameterFloat *PKF1gain;
    AudioParameterFloat *PKF2gain;
    AudioParameterFloat *PKF3gain;
    AudioParameterFloat *PKF4gain;
    AudioParameterFloat *PKF5gain;
    AudioParameterFloat *PKF6gain;
    AudioParameterFloat *HSFgain;
     */
    
    //Construct smoothing objects
    /*
    LinearSmoothedValue<float> *lowShelfSmooth;
    LinearSmoothedValue<float> *peakOneSmooth;
    LinearSmoothedValue<float> *peakTwoSmooth;
    LinearSmoothedValue<float> *peakThreeSmooth;
    LinearSmoothedValue<float> *peakFourSmooth;
    LinearSmoothedValue<float> *peakFiveSmooth;
    LinearSmoothedValue<float> *peakSixSmooth;
    LinearSmoothedValue<float> *highShelfSmooth;
     */
    
    AudioProcessorValueTreeState state;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GraphicEqAudioProcessor)
    
    //Construct Filter Objects
    /*
    Filter *lowShelf;
    Filter *peak250;
    Filter *peak500;
    Filter *peak1000;
    Filter *peak2000;
    Filter *peak4000;
    Filter *peak8000;
    Filter *highShelf;
     */
    
    Filter lowShelf;
    Filter peak250;
    Filter peak500;
    Filter peak1000;
    Filter peak2000;
    Filter peak4000;
    Filter peak8000;
    Filter highShelf;
    
    
};
