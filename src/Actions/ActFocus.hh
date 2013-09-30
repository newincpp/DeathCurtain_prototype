#ifndef _ACTFOCUS_H_
# define _ACTFOCUS_H_

class ActFocus : public DamnCute::AAction
{
    public:
        explicit ActFocus(DamnCute::APlayer *p, const std::string& texfile, int k) :
            AAction(p, k), _name("ActFocus")
        {
            _id = _player->_p.loadTex(texfile);
        }

        void execute()
        {
            _player->_p.render(_id);
        }

        const std::string getName() const
        {
            return (_name);
        }

        virtual ~ActFocus() {}

    private:
        int _id;
        const std::string _name;

};

#endif
