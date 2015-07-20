/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-Array.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFArrayRef wrapper
 */

#ifndef CFPP_ARRAY_H
#define CFPP_ARRAY_H

#include <vector>

namespace CF
{
    class CFPP_EXPORT Array: public PropertyListType< Array >
    {
        public:
            
            Array( void );
            Array( const Array & value );
            Array( const AutoPointer & value );
            Array( CFTypeRef value );
            Array( CFArrayRef value );
            
            #ifdef CFPP_HAS_CPP11
            Array( Array && value );
            #endif
            
            virtual ~Array( void );
            
            Array & operator = ( Array value );
            Array & operator = ( const AutoPointer & value );
            Array & operator = ( CFTypeRef value );
            Array & operator = ( CFArrayRef value );
            
            Array & operator += ( const Array & value );
            Array & operator += ( CFTypeRef value );
            Array & operator += ( CFArrayRef value );
            
            Array & operator << ( CFTypeRef value );
            Array & operator << ( const char * value );
            Array & operator << ( String value );
            Array & operator << ( Number value );
            
            CFTypeRef operator [] ( int index ) const;
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            CFIndex   GetCount( void ) const;
            bool      ContainsValue( CFTypeRef value ) const;
            void      RemoveAllValues( void ) const;
            CFTypeRef GetValueAtIndex( CFIndex index ) const;
            void      SetValueAtIndex( CFTypeRef value, CFIndex index ) const;
            void      InsertValueAtIndex( CFTypeRef value, CFIndex index ) const;
            void      AppendValue( CFTypeRef value ) const;
            void      RemoveValueAtIndex( CFIndex index ) const;
            void      AppendArray( CFArrayRef array ) const;
            void      ExchangeValuesAtIndices( CFIndex index1, CFIndex index2 ) const;
                        
            friend void swap( Array & v1, Array & v2 );
            
            class CFPP_EXPORT Iterator: public Type, public std::iterator< std::bidirectional_iterator_tag, CFTypeRef >
            {
                public:
                    
                    Iterator( void );
                    Iterator( const Iterator & value );
                    
                    #ifdef CFPP_HAS_CPP11
                    Iterator( Iterator && value );
                    #endif
                    
                    virtual ~Iterator( void );
                    
                    Iterator & operator = ( Iterator value );
                    Iterator & operator ++( void );
                    Iterator   operator ++( int );
                    Iterator & operator --( void );
                    Iterator   operator --( int );
                    
                    Iterator & operator += ( CFIndex value );
                    Iterator & operator -= ( CFIndex value );
                    
                    Iterator operator + ( CFIndex value );
                    Iterator operator - ( CFIndex value );
                    
                    bool operator == ( const Iterator & value ) const;
                    bool operator != ( const Iterator & value ) const;
                    
                    CFTypeRef operator * ( void ) const;
                    
                    operator CFTypeRef () const;
                    
                    CFTypeID  GetTypeID( void ) const;
                    CFTypeRef GetCFObject( void ) const;
                    
                    friend void swap( Iterator & v1, Iterator & v2 );
                    
                private:
                    
                    friend class Array;
                    
                    Iterator( CFArrayRef array, CFIndex count, CFIndex pos = 0 );
                    
                    CFArrayRef _cfObject;
                    CFIndex    _count;
                    CFIndex    _pos;
            };
            
            Iterator begin( void ) const;
            Iterator end( void ) const;
            
        protected:
            
            CFMutableArrayRef _cfObject;
    };
}

#endif /* CFPP_ARRAY_H */
